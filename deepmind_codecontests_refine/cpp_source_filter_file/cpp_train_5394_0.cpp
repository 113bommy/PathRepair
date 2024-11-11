#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, L;
  cin >> N;
  int P = 0;
  int M = 0;
  for (int i = 0; i < N; i++) {
    cin >> L;
    P += L;
    M = max(M, L);
  }
  cout << (P < M * 2 ? "Yes" : "No");
}
