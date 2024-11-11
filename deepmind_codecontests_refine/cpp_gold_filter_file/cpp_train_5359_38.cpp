#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fastio();
  int n, m, temp;
  cin >> n >> m;
  vector<int> boys(n);
  vector<int> girls(m);
  int hb;
  cin >> hb;
  for (int i = 0; i < hb; i++) cin >> temp, boys[temp] = 1;
  int hg;
  cin >> hg;
  for (int i = 0; i < hg; i++) cin >> temp, girls[temp] = 1;
  int len = 100 * 100;
  int a, b;
  for (int i = 0; i < len; i++) {
    a = i % n;
    b = i % m;
    if (boys[a] == 1 || girls[b] == 1) boys[a] = 1, girls[b] = 1;
  }
  for (int i = 0; i < n; i++)
    if (boys[i] == 0) {
      cout << "No\n";
      return 0;
    }
  for (int i = 0; i < m; i++)
    if (girls[i] == 0) {
      cout << "No\n";
      return 0;
    }
  cout << "Yes\n";
  return 0;
}
