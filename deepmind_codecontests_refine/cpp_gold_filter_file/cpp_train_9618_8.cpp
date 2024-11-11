#include <bits/stdc++.h>
using namespace std;
inline int Get_Int() {
  int Num = 0, Flag = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') Flag = -Flag;
  } while (ch < '0' || ch > '9');
  do {
    Num = Num * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return Num * Flag;
}
int N, Ans, Win;
int P[5005], F[5005];
char S[5005];
inline int Mex(vector<int> &A) {
  int Min = 0;
  while (true) {
    bool Flag = true;
    for (typeof(A.begin()) it = A.begin(); it != A.end(); ++it)
      if (*it == Min) {
        Flag = false;
        ++Min;
        break;
      }
    if (Flag) return Min;
  }
}
int Solve(int Left, int Right) {
  int Ans = 0, Total = 0;
  for (int i = Left + 1; i < Right; ++i)
    if (P[i] > 1)
      ++Total;
    else {
      Ans ^= F[Total + 2];
      Total = 0;
    }
  Ans ^= F[Total + 2];
  return Ans;
}
int main() {
  scanf("%s", S + 1);
  N = strlen(S + 1);
  S[0] = '$';
  S[N + 1] = '#';
  for (int i = 3; i <= N; ++i) {
    vector<int> temp;
    for (int j = 2; j < i; ++j) temp.push_back(F[j - 1] ^ F[i - j]);
    F[i] = Mex(temp);
  }
  for (int i = 1; i <= N; ++i)
    while (S[i - P[i]] == S[i + P[i]]) ++P[i];
  for (int i = 1; i <= N; ++i)
    if (P[i] > 1)
      if (Solve(1, i - 1) == Solve(i + 1, N)) {
        Win = true;
        Ans = i;
        break;
      }
  if (Win)
    cout << "First" << endl << Ans << endl;
  else
    cout << "Second" << endl;
  return 0;
}
