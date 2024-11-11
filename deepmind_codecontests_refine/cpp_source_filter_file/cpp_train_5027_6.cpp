#include <bits/stdc++.h>
using namespace std;
vector<int> A;
int solve(vector<int> a, int bit) {
  if (bit == -1) return 0;
  if (a.size() == 0) return 0;
  vector<int> a1, a2;
  for (auto x : a) {
    if ((x >> bit) & 1)
      a1.push_back(x);
    else
      a2.push_back(x);
  }
  return min(max(0, (int)a1.size() - 1) + solve(a2, bit - 1),
             max(0, (int)a2.size() - 1) + solve(a1, bit - 1));
}
int main() {
  int n;
  cin >> n;
  A.resize(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  cout << solve(A, 32);
}
