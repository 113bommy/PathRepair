#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
template <class T>
typename T::value_type arr_sum(const T& v, int n) {
  typename T::value_type sum = 0;
  for (int i = (0); i < (n); ++i) sum += v[i];
  return sum;
}
struct Sync_stdio {
  Sync_stdio() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }
} _sync_stdio;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < (n); ++i) cin >> v[i];
  ;
  int m;
  cin >> m;
  vector<int> a(n);
  for (int i = (0); i < (m); ++i) {
    int x;
    cin >> x;
    --x;
    ++a[x];
  }
  long long res = 0;
  long long loop = min(a[0], a[n - 1]);
  for (int i = (1); i < (n - 1); ++i) {
    loop = min(loop, (long long)a[i] / 2);
  }
  for (int i = (1); i < (n - 1); ++i) {
    a[i] -= 2 * loop;
  }
  a[0] -= loop;
  a[n - 1] -= loop;
  res += loop * 2 * (v[n - 1] - v[0]);
  if (count(a.begin(), a.end(), 0) == a.size()) {
    for (int i = (2); i < (n); ++i) {
      if (v[i] - v[i - 1] != v[1] - v[0]) {
        cout << -1 << "\n";
        return 0;
      }
    }
    cout << res - (v[1] - v[0]);
    return 0;
  }
  if (count(a.begin(), a.end(), 2) == 0) {
    int pos1 = find(a.begin(), a.end(), 1) - a.begin();
    int pos2 = n - 1 - (find(a.rbegin(), a.rend(), 1) - a.rbegin());
    cout << res + v[pos2] - v[pos1];
    return 0;
  }
  if (a[0] == 1 && a[n - 1] != 1) {
    int pos1 = n - 1 - (find(a.rbegin(), a.rend(), 2) - a.rbegin());
    int pos2 = n - 1 - (find(a.rbegin(), a.rend(), 1) - a.rbegin());
    pos2 = max(pos2, pos1);
    cout << res + (v[pos2] - v[0]) + (v[pos1] - v[0]);
    return 0;
  }
  if (a[0] != 1 && a[n - 1] == 1) {
    int pos1 = find(a.begin(), a.end(), 2) - a.begin();
    int pos2 = find(a.begin(), a.end(), 1) - a.begin();
    pos2 = min(pos2, pos1);
    cout << res + (v[n - 1] - v[pos2]) + (v[n - 1] - v[pos1]);
    return 0;
  }
  if (a[1] == 1) {
    int pos1 = find(a.begin(), a.end(), 2) - a.begin();
    cout << res + (v[n - 1] - v[0]) + (v[n - 1] - v[pos1]);
    return 0;
  }
  if (a[n - 2] == 1) {
    int pos1 = n - 1 - (find(a.rbegin(), a.rend(), 2) - a.rbegin());
    cout << res + (v[n - 1] - v[0]) + (v[pos1] - v[0]);
    return 0;
  }
  int pos1 = find(a.begin() + 1, a.end(), 1) - a.begin() - 1;
  int pos2 = n - 1 - (find(a.rbegin(), a.rend(), 2) - a.rbegin());
  cout << res + (v[pos1] - v[0]) + (v[n - 1] - v[0]) + (v[n - 1] - v[pos2]);
  return 0;
}
