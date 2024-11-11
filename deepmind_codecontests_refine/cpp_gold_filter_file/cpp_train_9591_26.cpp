#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << "\b\b]\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H << ", ";
  dbg_out(T...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  int t = 0, s = 0;
  for (int &i : A) {
    cin >> i;
    t += (i == 1);
    s += (i == -1);
  }
  int ans = 0;
  for (int i = 0; i < k; i++) {
    int test = 0, social = 0;
    for (int j = i; j < n; j += k) {
      if (A[j] == 1)
        test++;
      else
        social++;
    }
    test = t - test;
    social = s - social;
    ans = max(ans, abs(test - social));
  }
  cout << ans;
  return 0;
}
