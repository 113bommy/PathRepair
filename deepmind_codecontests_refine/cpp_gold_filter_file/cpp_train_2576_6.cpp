#include <bits/stdc++.h>
template <class T>
bool MX(T &l, const T &r) {
  return l < r ? l = r, 1 : 0;
}
template <class T>
bool MN(T &l, const T &r) {
  return l > r ? l = r, 1 : 0;
}
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k, p = -1, h = -1, fh = -1, ans = 0;
  cin >> n >> m;
  k = n / m;
  vector<vector<long long> > mod(m);
  vector<long long> a(n);
  for (int i = 0; i < (int)n; ++i) {
    cin >> a[i];
    mod[a[i] % m].push_back(i);
  }
  for (int i = 0; i < (int)m; ++i)
    if (p == -1 && (int)(mod[i]).size() > k)
      p = i;
    else if (p != -1 && (int)(mod[i]).size() < k) {
      h = i;
      break;
    } else if (fh == -1 && (int)(mod[i]).size() < k)
      fh = i;
  if (p == -1) {
    cout << "0\n";
    for (int i = 0; i < (int)n; ++i) cout << a[i] << " ";
    cout << endl;
    return 0;
  } else if (h == -1)
    h = fh + m;
  while (p < m) {
    if ((int)(mod[p]).size() <= k) {
      ++p;
      continue;
    }
    if (p > h || (int)(mod[h % m]).size() >= k) {
      ++h;
      continue;
    }
    fh = min(k - (int)(mod[h % m]).size(), (int)(mod[p]).size() - k);
    for (int i = 0; i < (int)fh; ++i)
      a[mod[p][(int)(mod[p]).size() - i - 1]] += h - p;
    ans += fh * (h - p);
    mod[h % m].resize((int)(mod[h % m]).size() + fh);
    mod[p].resize((int)(mod[p]).size() - fh);
  }
  cout << ans << endl;
  for (int i = 0; i < (int)n; ++i) cout << a[i] << " ";
  cout << endl;
  return 0;
}
