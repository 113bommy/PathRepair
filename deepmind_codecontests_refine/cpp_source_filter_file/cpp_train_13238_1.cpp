#include <bits/stdc++.h>
using namespace std;
class dop {
 public:
  long long int n, m, p, q, r, x;
  vector<long long int> a, b;
  void get();
};
void dop::get() {
  cin >> n >> m;
  for (long long int i = 0; i < n; i++) {
    cin >> p;
    a.push_back(p);
  }
  for (long long int i = 0; i < 100; i++) {
    b.push_back(0);
  }
  for (long long int i = 0; i < n; i++) {
    if (m >= ((i * 100) + a[i])) {
      cout << i << " ";
      b[a[i] - 1]++;
      continue;
    }
    q = 0;
    r = 0;
    p = m - a[i];
    for (long long int j = 0; j < 100; j++) {
      if ((q + (b[j] * (j + 1))) <= p) {
        q += b[j] * (j + 1);
        r += b[j];
      } else {
        x = (p - q) / (j + 1);
        q += (x * (j + 1));
        r += x;
        break;
      }
    }
    b[a[i] - 1]++;
    cout << i - r << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  dop obj[t];
  for (long long int i = 0; i < t; i++) {
    obj[i].get();
  }
  return 0;
}
