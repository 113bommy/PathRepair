#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(vector<T> &a, long long n) {
  T x;
  a.clear();
  for (long long i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
}
template <class T>
void write(vector<T> &a) {
  for (T x : a) cout << x << " ";
  cout << endl;
}
const int N = 200005;
long long a[N];
int nxt[N];
long long k;
int n;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    nxt[i] = i;
  }
  nxt[n] = n;
  for (int i = n - 1; i >= 0; i--)
    if (a[i] == 1) nxt[i] = max(nxt[i], nxt[i + 1]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    long long p = 1;
    long long second = 0;
    int pos = i;
    while (pos < n) {
      if (a[pos] == 1) {
        int l = 0;
        int r = nxt[pos] - pos;
        while (r > l) {
          int md = (r + l) / 2;
          if (p > k * (second + md))
            l = md + 1;
          else
            r = md;
        }
        if (p == k * (second + l)) {
          ans++;
        }
        second += nxt[pos] - pos;
        pos = nxt[pos];
        continue;
      }
      p *= a[pos];
      second += a[pos];
      if (p > 1LL * 1000 * 1000 * 1000) break;
      if (p == k * second) {
        ans++;
      }
      pos++;
    }
  }
  cout << ans;
}
