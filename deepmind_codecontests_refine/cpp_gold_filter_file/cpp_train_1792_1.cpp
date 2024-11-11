#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000")
#pragma warning(disable : 6031)
#pragma warning(disable : 4244)
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long mod = int(1e9) + 7;
const double eps9 = 1e-9;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << setprecision(18) << fixed;
  string s;
  cin >> s;
  vector<pair<int, int> > a;
  for (int i = 0; i < (int)(s).size(); i++) {
    int cur = 0;
    for (int j = i; j < (int)(s).size(); j++) {
      if (s[i] == s[j])
        cur++;
      else
        break;
    }
    a.emplace_back(s[i], cur);
    i += cur - 1;
  }
  if ((int)(a).size() % 2 == 0) {
    cout << 0;
    return 0;
  }
  int mid = (int)(a).size() / 2;
  if (a[mid].second < 2) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= mid; i++) {
    if (a[mid - i].first != a[mid + i].first) {
      cout << 0;
      return 0;
    }
    if (a[mid - i].second + a[mid + i].second < 3) {
      cout << 0;
      return 0;
    }
  }
  cout << a[mid].second + 1;
  return 0;
}
