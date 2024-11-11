#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18L;
constexpr int mod = int(1e9) + 7;
long long t = 1, n, k;
void solve() {
  int a, b;
  cin >> a >> b;
  if (b > a) swap(a, b);
  int temp = b;
  a -= b;
  b -= b;
  vector<int> ans;
  int i = 1;
  while (b <= temp) {
    int bruh = (a + b) / 2;
    ans.push_back(bruh * i);
    if ((a + b) % 2) {
      ans.push_back(bruh * i + 1);
    }
    a++;
    b++;
    i++;
  }
  cout << (int)ans.size() << "\n";
  for (auto i : ans) cout << i << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) solve();
  return 0;
}
