#include <bits/stdc++.h>
using namespace std;
int knight[100000];
int is_possible(int t, int n) {
  vector<int> r(t, 1);
  for (int i = 0; i < n; i++) r[i % t] &= knight[i];
  for (int i = 0; i < r.size(); i++)
    if (r[i]) return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> knight[i];
  for (int i = 1; i * 3 <= n; i++) {
    if (n % i == 0 and is_possible(i, n)) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
