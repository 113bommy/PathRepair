#include <bits/stdc++.h>
using namespace std;
int A[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string line;
  map<int, int> B;
  for (int i = 0; i < n; ++i) {
    cin >> line;
    for (char c : line) A[i] ^= 1 << (c - 'a');
    B[A[i]] += 1;
  }
  long long mx = 0;
  for (int i = 0; i < n; ++i) {
    mx += B[A[i]] - 1;
    for (int j = 0; j < 26; ++j) mx += B[A[i] ^ (1 << j)];
  }
  cout << (mx >> 1);
  return 0;
}
