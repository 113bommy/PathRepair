#include <bits/stdc++.h>
using namespace std;
void printvec(vector<long long int> tmp) {
  for (long long int i = 0; i < tmp.size(); i++) {
    cout << tmp[i] << " ";
  }
  cout << '\n';
}
vector<long long int> f, l;
long long int cal(long long int k) {
  long long int s = 0;
  long long int e = l.size() - 1;
  long long int ans = -1;
  while (s <= e) {
    long long int m = (s + e) / 2;
    if (l[m] < k) {
      s = m + 1;
    } else {
      ans = m;
      e = m - 1;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  long long int ar[n + 1];
  for (long long int i = 1; i <= n; i++) cin >> ar[i];
  long long int ans = 0;
  long long int s = 0;
  for (long long int i = 1; i <= n; i++) s += ar[i];
  if (s % 3 != 0) {
    cout << 0 << '\n';
    return 0;
  }
  s /= 3;
  long long int ts = 0;
  for (long long int i = 1; i <= n; i++) {
    ts += ar[i];
    if (ts == s) f.push_back(i);
  }
  ts = 0;
  for (long long int i = n; i >= 1; i--) {
    ts += ar[i];
    if (ts == s) l.push_back(i);
  }
  reverse(l.begin(), l.end());
  for (long long int i = 0; i < f.size(); i++) {
    long long int index = f[i];
    long long int j = cal(index);
    if (j != -1) {
      ans += (l.size() - j);
    }
  }
  cout << ans << '\n';
  return 0;
}
