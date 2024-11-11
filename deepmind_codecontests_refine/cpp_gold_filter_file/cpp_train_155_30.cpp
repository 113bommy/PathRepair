#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000;
int n, k;
int a, b, c, d;
int num[MAXN], num_cnt = 0;
int rank[MAXN];
set<int> s;
vector<int> v;
int main() {
  cin >> n >> k;
  cin >> a >> b >> c >> d;
  if (k <= n) {
    cout << -1 << endl;
  } else {
    if (n >= 5) {
      for (int i = 1; i <= n; ++i) {
        if (i != a && i != b && i != c && i != d) {
          s.insert(i);
        }
      }
      v.push_back(a);
      v.push_back(c);
      while (!s.empty()) {
        v.push_back(*s.begin());
        s.erase(s.begin());
      }
      v.push_back(d);
      v.push_back(b);
      for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
      }
      cout << endl;
      cout << c << " " << a << " ";
      for (int i = (int)v.size() - 3; i >= 2; --i) {
        cout << v[i] << " ";
      }
      cout << b << " " << d << endl;
    } else if (n == 4) {
      cout << -1 << endl;
    }
  }
}
