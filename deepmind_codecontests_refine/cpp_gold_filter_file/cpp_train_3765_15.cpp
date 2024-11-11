#include <bits/stdc++.h>
using namespace std;
const long long int N = 300005;
long long int last[N], dist[N], a[N], pre[N];
vector<long long int> one;
long long int n, ans;
void find(long long int l, long long int r, long long int one) {
  ans++;
  long long int mx = 0;
  for (long long int i = one - 1; i >= l; i--) {
    mx = max(a[i], mx);
    long long int j = i + mx - 1;
    if (j > n) continue;
    long long int val = pre[j] - pre[i - 1];
    long long int x = j - i + 1;
    if (dist[j] < i && val == (x * (x + 1)) / 2) ans++;
  }
  mx = 0;
  for (long long int i = one + 1; i <= r; i++) {
    mx = max(a[i], mx);
    long long int j = i - mx + 1;
    if (j < 1) continue;
    long long int val = pre[i] - pre[j - 1];
    long long int x = i - j + 1;
    if (dist[i] < j && val == (x * (x + 1)) / 2) ans++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n;
  one.push_back(0);
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
    dist[i] = max(dist[i - 1], last[a[i]]);
    last[a[i]] = i;
    if (a[i] == 1) one.push_back(i);
  }
  one.push_back(n + 1);
  for (long long int i = 1; i < one.size() - 1; i++) {
    long long int l = one[i - 1] + 1, r = one[i + 1] - 1;
    find(l, r, one[i]);
  }
  cout << ans;
}
