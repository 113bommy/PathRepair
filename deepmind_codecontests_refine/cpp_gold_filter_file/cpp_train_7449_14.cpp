#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double E = exp(1);
const int N = 2e5 + 5;
long long n, k, x;
long long a[N];
int ct = 0, zero = 0;
int imen = 0;
bool sozero() { return zero > k; }
bool posi() {
  if ((ct % 2)) return false;
  if (zero) return false;
  int i = imen;
  return abs(a[i]) - k * x >= 0;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (abs(a[i]) < abs(a[imen])) imen = i;
    if (a[i] == 0) zero++;
    if (a[i] < 0) ct++;
  }
  if (sozero()) {
    cout << a[0] + k * x << " ";
    for (int i = 1; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
  }
  if (posi()) {
    for (int i = 0; i < n; i++) {
      if (i == imen) {
        if (a[i] > 0) {
          cout << a[i] - k * x << " ";
        } else {
          cout << a[i] + k * x << " ";
        }
      } else {
        cout << a[i] << " ";
      }
    }
    cout << endl;
    return 0;
  }
  set<pair<long long, int> > s;
  for (int i = 0; i < n; i++) {
    if (!a[i]) {
      if (!(ct % 2)) {
        a[i] -= x;
        k--;
        ct++;
      } else {
        a[i] += x;
        k--;
      }
    }
  }
  if (!(ct % 2)) {
    int i = imen;
    if (a[i] > 0) {
      while (a[i] >= 0) {
        a[i] -= x;
        k--;
      }
    } else {
      while (a[i] <= 0) {
        a[i] += x;
        k--;
      }
    }
  }
  for (int i = 0; i < n; i++) s.insert(make_pair(abs(a[i]), i));
  while (k--) {
    int i = s.begin()->second;
    s.erase(s.begin());
    if (a[i] < 0) {
      a[i] -= x;
    } else {
      a[i] += x;
    }
    s.insert(make_pair(abs(a[i]), i));
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
