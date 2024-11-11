#include <bits/stdc++.h>
using namespace std;
int Q, N, M, K, L;
char A[2001], B[2001];
vector<int> ret;
void flip(int n) {
  ret.push_back(n);
  char tmp[2001];
  for (int i = N - 1, j = 0; i >= n; i--, j++) tmp[j] = A[i];
  for (int i = n - 1, j = N - 1; i >= 0; i--, j--) A[j] = A[i];
  for (int i = 0; i < N - n; i++) A[i] = tmp[i];
}
int main() {
  cin >> N >> A >> B;
  vector<char> C, D;
  for (int i = 0; i < N; i++) {
    C.push_back(A[i]);
    D.push_back(B[i]);
  }
  sort(C.begin(), C.end());
  sort(D.begin(), D.end());
  if (C != D) {
    cout << -1;
    return 0;
  }
  if (N == 1) {
    cout << 0;
    return 0;
  }
  int a, b;
  for (int i = 0; i < N; i++) {
    if (A[i] == B[0]) a = i;
    if (A[i] == B[1] && a != i) b = i;
  }
  int len = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j >= a && j < a + len) continue;
      if (A[j] == B[i]) b = j;
    }
    if (a > b) {
      int Alen = b;
      int Blen = a - b - 1;
      int Clen = N - a - len;
      flip(b + 1);
      flip(N - 1);
      flip(1 + Clen);
      a = Alen + Blen;
      len++;
    } else {
      int Alen = a;
      int Blen = b - a - 1;
      int Clen = N - b - 1;
      flip(b + 1);
      flip(0);
      flip(1 + Blen);
      a = Clen + Alen;
      len++;
    }
  }
  cout << ret.size() << "\n";
  for (auto x : ret) cout << x << " ";
  cin >> N;
}
