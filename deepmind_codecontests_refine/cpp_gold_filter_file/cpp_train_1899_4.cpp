#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int dr8[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dc8[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dr4[] = {0, 1, -1, 0};
int dc4[] = {1, 0, 0, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int d, m;
    cin >> d >> m;
    int tm = d;
    vector<int> v;
    int i = 0;
    while (tm > 0) {
      if (tm < 2) break;
      v.push_back(1 << i);
      i++;
      tm /= 2;
    }
    v.push_back(d - ((1 << i) - 1));
    int sz = v.size();
    int an = v[sz - 1] % m;
    for (int i = sz - 2; i >= 0; i--) {
      int add = (1ll * v[i] + an) % m;
      add = (1ll * add + (1ll * v[i] * an) % m) % m;
      an = add;
    }
    cout << an << "\n";
  }
}
