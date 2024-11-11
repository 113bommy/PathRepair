#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int countbit(T n) {
  return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}
template <class T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
const double EPS = 1e-9;
const double PI = acos(-1.0);
int main(void) {
  int l, b, f;
  cin >> l >> b >> f;
  int q;
  cin >> q;
  vector<pair<int, int> > ocupado(1, pair<int, int>(l + f, l + f + 1));
  vector<pair<int, int> > used(q);
  for (int k = 0; k < int(q); k++) {
    int a, x;
    cin >> a >> x;
    if (a == 1) {
      bool found = false;
      if (x + f <= ocupado[0].first) {
        used[k] = pair<int, int>(0, x);
        ocupado.insert(ocupado.begin(), pair<int, int>(0, x));
        cout << 0 << endl;
        found = true;
      }
      for (int i = 0; i < ((int)(ocupado.size())) - 1 && !found; i++) {
        if (ocupado[i + 1].first - ocupado[i].second >= x + b + f) {
          ocupado.insert(
              ocupado.begin() + i + 1,
              pair<int, int>(ocupado[i].second + b, ocupado[i].second + b + x));
          used[k] =
              pair<int, int>(ocupado[i].second + b, ocupado[i].second + b + x);
          cout << ocupado[i].second + b << endl;
          found = true;
        }
      }
      sort((ocupado).begin(), (ocupado).end());
      if (!found) cout << -1 << endl;
    } else if (a == 2) {
      int i = used[x - 1].first;
      int j = used[x - 1].second;
      for (int t = 0; t < ((int)(ocupado.size())); t++) {
        if (ocupado[t].first == i && ocupado[t].second == j) {
          ocupado.erase(ocupado.begin() + t);
          break;
        }
      }
    }
  }
  return 0;
}
