#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& out, vector<T> v) {
  for (T t : v) out << t << ' ';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, set<T> v) {
  for (T t : v) out << t << ' ';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, pair<T, T> v) {
  out << v.first << ' ' << v.second;
  return out;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<long long> a(n, 0), b(n, 0);
  for (int i = 0; i < n; ++i) cin >> b[i];
  int posi = -1;
  for (int i = 0; i < n; ++i) {
    int j = (i + n - 1) % n;
    if (b[i] > b[j]) {
      posi = i;
      break;
    }
  }
  if (posi == -1) {
    if (b[0] == 0) {
      cout << "YES\n";
      for (int i = 0; i < n; ++i) cout << 1 << ' ';
      return 0;
    }
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  a[posi] = b[posi];
  for (int count = 1; count < n; ++count) {
    int next = (posi + n - 1) % n;
    int twonext = (posi + n - 2) % n;
    long long k = max(0ll, (b[twonext] - b[next]) / a[posi]);
    a[next] = b[next] + k * a[posi];
    while (a[next] <= b[twonext]) a[next] += a[posi];
    posi = next;
  }
  cout << a;
  return 0;
}
