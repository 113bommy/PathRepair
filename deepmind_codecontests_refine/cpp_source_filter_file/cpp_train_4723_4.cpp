#include <bits/stdc++.h>
using namespace std;
const int Len = 15;
struct BigNumber {
  int X[Len];
  void Set(int A) {
    memset(X, 0, sizeof(X));
    X[0] = A;
  }
  void Output() {
    int P = Len - 1;
    while (P && !X[P]) P--;
    printf("%d", X[P]);
    while (P) {
      static int A[8];
      P--;
      for (int i = 0; i < 8; i++) {
        A[i] = X[P] % 10;
        X[P] /= 10;
      }
      for (int i = 7; i >= 0; i--) putchar(A[i] + 48);
    }
    putchar('\n');
  }
};
bool operator<(BigNumber A, BigNumber B) {
  int P = Len - 1;
  while (P && A.X[P] == B.X[P]) P--;
  return A.X[P] < B.X[P];
}
BigNumber operator*(BigNumber A, int P) {
  BigNumber B;
  for (int i = 0, G = 0; i < Len; i++) {
    long long S = (long long)A.X[i] * P + G;
    G = S / 100000000;
    B.X[i] = S % 100000000;
  }
  return B;
}
BigNumber operator*(BigNumber A, BigNumber B) {
  static long long S[Len];
  memset(S, 0, sizeof(S));
  for (int i = 0; i < Len; i++)
    for (int j = 0; j < Len; j++) S[i + j] += (long long)A.X[i] * B.X[j];
  for (int i = 1; i < Len; i++) S[i] += S[i - 1] / 100000000;
  BigNumber C;
  for (int i = 0; i < Len; i++) C.X[i] = S[i] % 100000000;
  return C;
}
int Get() {
  char c;
  while (c = getchar(), c < '0' || c > '9')
    ;
  int X = c - 48;
  while (c = getchar(), c >= '0' && c <= '9') X = X * 10 + c - 48;
  return X;
}
int N;
vector<int> G[700], Child[700];
int Next[700], Right[700];
BigNumber F[700][703];
bool Flag[700][701];
void DFS(int Last, int X) {
  int Pre = -1;
  for (int i = 0; i < G[X].size(); i++)
    if (G[X][i] != Last) {
      Child[X].push_back(G[X][i]);
      DFS(X, G[X][i]);
      if (Pre != -1) Next[Pre] = G[X][i];
      Pre = G[X][i];
    }
  for (int i = 0; i < Child[X].size(); i++)
    Right[Child[X][i]] = Child[X].size() - i;
}
BigNumber DP(int X, int S) {
  BigNumber Ans;
  Ans.Set(0);
  if (S < 0 || (S < N && S > Right[X])) return Ans;
  if (Flag[X][S]) return F[X][S];
  Flag[X][S] = true;
  if (Child[X].empty()) {
    if (S == N + 1)
      Ans.Set(2);
    else if (S == N || S == N + 2 || Next[X] == -1)
      Ans.Set(1);
    else
      Ans = max(DP(Next[X], S - 1), DP(Next[X], S));
  } else if (S == N + 2) {
    Ans.Set(1);
    for (int i = 0; i < Child[X].size(); i++) Ans = Ans * DP(Child[X][i], N);
  } else if (S == N + 1) {
    Ans = DP(X, N + 2) * 2;
    for (int i = 0; i <= Child[X].size(); i++)
      Ans = max(Ans, DP(Child[X][0], i) * (i + 2));
  } else if (S == N) {
    Ans = DP(X, N + 2);
    for (int i = 0; i <= Child[X].size(); i++)
      Ans = max(Ans, DP(Child[X][0], i) * (i + 1));
    int Best = 0;
    BigNumber P = DP(Child[X][0], N + 1);
    BigNumber Q = DP(Child[X][0], N);
    for (int i = 1; i < Child[X].size(); i++) {
      BigNumber _P = DP(Child[X][i], N + 1);
      BigNumber _Q = DP(Child[X][i], N);
      if (P * _Q < _P * Q) {
        Best = i;
        P = _P;
        Q = _Q;
      }
    }
    BigNumber Temp;
    Temp.Set(1);
    for (int i = 0; i < Child[X].size(); i++)
      Temp = Temp * DP(Child[X][i], N + (i == Best));
    Ans = max(Ans, Temp);
  } else if (Next[X] == -1)
    Ans = DP(X, N + S * 2);
  else
    Ans = max(DP(X, N + 2) * DP(Next[X], S - 1), DP(X, N) * DP(Next[X], S));
  return F[X][S] = Ans;
}
int main() {
  N = Get();
  for (int i = 1; i < N; i++) {
    int X = Get() - 1, Y = Get() - 1;
    G[X].push_back(Y);
    G[Y].push_back(X);
  }
  memset(Next, -1, sizeof(Next));
  DFS(-1, 0);
  DP(0, N).Output();
  return 0;
}
