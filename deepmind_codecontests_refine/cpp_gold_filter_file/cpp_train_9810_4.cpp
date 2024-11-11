#include <bits/stdc++.h>
using namespace std;
long long y = 1000000007;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return (a.first < b.first) || (a.first == b.first && a.second > b.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, a, b;
    cin >> s;
    a = s;
    vector<int> v;
    b = s;
    int y = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      if (s[i] == a[0]) v.push_back(i);
    }
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == 0)
        continue;
      else if (v[i] == n - 1) {
        string h = s;
        reverse(h.begin(), h.end());
        if (h < b) {
          b = h;
          y = v[i];
        }
      } else {
        string h = s.substr(v[i], n - v[i]);
        if (v[i] % 2 != n % 2) {
          string y1 = s.substr(0, v[i]);
          reverse(y1.begin(), y1.end());
          h = h + y1;
        } else {
          string y1 = s.substr(0, v[i]);
          h = h + y1;
        }
        if (h < b) {
          b = h;
          y = v[i];
        }
      }
    }
    cout << b << endl << y + 1 << endl;
  }
}
