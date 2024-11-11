#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MOD = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string str1, str2;
  cin >> str1 >> str2;
  vector<int> A(n), B(n);
  for (int i = 0; i < (n); ++i) A[i] = str1[i] - '0';
  for (int i = 0; i < (n); ++i) B[i] = str2[i] - '0';
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int ai = 0, bi = 0;
  while (bi < n) {
    if (A[ai] <= B[bi]) ai++;
    bi++;
  }
  cout << n - ai << '\n';
  ai = 0, bi = 0;
  while (bi < n) {
    if (A[ai] < B[bi]) ai++;
    bi++;
  }
  cout << ai << '\n';
  return 0;
}
