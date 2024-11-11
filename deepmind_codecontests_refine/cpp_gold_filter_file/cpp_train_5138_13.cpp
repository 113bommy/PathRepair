#include <bits/stdc++.h>
using namespace std;
void Get(int &T) {
  char C;
  bool F = 0;
  for (; C = getchar(), C < '0' || C > '9';)
    if (C == '-') F = 1;
  for (T = C - '0'; C = getchar(), C >= '0' && C <= '9'; T = T * 10 + C - '0')
    ;
  F && (T = -T);
}
void Get(long long &T) {
  char C;
  bool F = 0;
  for (; C = getchar(), C < '0' || C > '9';)
    if (C == '-') F = 1;
  for (T = C - '0'; C = getchar(), C >= '0' && C <= '9'; T = T * 10 + C - '0')
    ;
  F && (T = -T);
}
int N;
int K;
long long A;
long long X;
long long Y;
long long Mod;
vector<pair<pair<int, int>, short> > S;
int Ans;
void Init() {
  Get(N);
  for (int k = 1; k <= N; k++) {
    Get(K);
    Get(A);
    Get(X);
    Get(Y);
    Get(Mod);
    long long Last = -1;
    int Level = 0;
    for (int j = 1; j <= K; j++) {
      if (Last > A) Level++;
      if (S.size() <= 200000)
        S.push_back(make_pair(make_pair(Level, A), (short)k));
      Ans = std::max(Level, Ans);
      Last = A;
      (A = A * X + Y) %= Mod;
    }
  }
}
void Work() { sort(S.begin(), S.end()); }
void Output() {
  printf("%d\n", Ans);
  if (S.size() <= 200000) {
    for (vector<pair<pair<int, int>, short> >::iterator i = S.begin();
         i != S.end(); i++) {
      printf("%d %d\n", i->first.second, i->second);
    }
  }
}
int main() {
  Init();
  Work();
  Output();
  return 0;
}
