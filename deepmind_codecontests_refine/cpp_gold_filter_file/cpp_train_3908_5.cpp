#include <bits/stdc++.h>
using namespace std;
const int N = 500010, LG = 20, INF = 1e9;
int n, sum[N], a[N], nr[N];
int sa[N], suf[N][LG], lcp[N];
long long res;
vector<int> val[N << 1];
string s;
int get(int x, int y) {
  int t = sum[x - 1] + N;
  y = min(y, nr[x - 1]);
  if (x > y) return 0;
  int l = lower_bound(val[t].begin(), val[t].end(), x) - val[t].begin();
  int r = lower_bound(val[t].begin(), val[t].end(), y + 1) - val[t].begin() - 1;
  return r - l + 1;
}
pair<int, int> A[N];
pair<pair<int, int>, int> AA[N];
void build() {
  int cnt = 0;
  for (int i = 1; i <= n; i++) A[i] = pair<int, int>(a[i], i);
  sort(A + 1, A + n + 1);
  for (int i = 1; i <= n; i++)
    suf[A[i].second][0] = (A[i].first == A[i - 1].first) ? cnt : ++cnt;
  for (int i = 0; i < LG - 1; i++) {
    cnt = 0;
    for (int j = 1; j <= n; j++)
      (j + (1 << i) <= n)
          ? AA[j] = pair<pair<int, int>, int>(
                pair<int, int>(suf[j][i], suf[j + (1 << i)][i]), j)
          : AA[j] =
                pair<pair<int, int>, int>(pair<int, int>(suf[j][i], -INF), j);
    sort(AA + 1, AA + n + 1);
    for (int j = 1; j <= n; j++)
      suf[AA[j].second][i + 1] = (AA[j].first == AA[j - 1].first) ? cnt : ++cnt;
  }
  for (int i = 1; i <= n; i++) sa[suf[i][LG - 1]] = i;
}
int find_lcp(int x, int y) {
  int ans = 0;
  for (int i = LG - 1; i >= 0; i--)
    if (x + (1 << i) <= n + 1 && y + (1 << i) <= n + 1 &&
        suf[x][i] == suf[y][i])
      x += (1 << i), y += (1 << i), ans += (1 << i);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  s = '!' + s;
  for (int i = 1; i <= n; i++) a[i] = ((s[i] == '(') ? 1 : -1);
  val[N].push_back(0);
  for (int i = 1; i <= n; i++)
    sum[i] = sum[i - 1] + a[i], val[sum[i] + N].push_back(i);
  stack<int> st;
  for (int i = n; i >= 0; i--) {
    while (!st.empty() && sum[st.top()] >= sum[i]) st.pop();
    if (!st.empty())
      nr[i] = st.top() - 1;
    else
      nr[i] = n;
    st.push(i);
  }
  build();
  res = get(sa[1], n);
  for (int i = 2; i <= n; i++) {
    lcp[i] = find_lcp(sa[i - 1], sa[i]);
    res += get(sa[i], n);
    res -= get(sa[i], sa[i] + lcp[i] - 1);
  }
  cout << res << endl;
}
