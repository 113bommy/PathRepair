#include <bits/stdc++.h>
using namespace std;
int n, arr[200005], r[200005], l[200005], freq[200005], now, ans, q;
bool ch[200005];
vector<pair<int, int> > v;
void ubah(int ki, int ka, int col) {
  int upki = ki;
  int upka = ka;
  for (int i = ki; i <= ka; i++) {
    if (arr[i] != now) {
      ans++;
      upki = min(upki, l[arr[i]]);
      upka = max(upka, r[arr[i]]);
      ch[arr[i]] = 1;
      arr[i] = now;
    }
  }
  if (upka != ka) ubah(ka + 1, upka, col);
  if (upki != ki) ubah(upki, ki - 1, col);
}
int main() {
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
    freq[arr[i]]++;
    if (freq[arr[i]] == 1) l[arr[i]] = i;
    r[arr[i]] = i;
  }
  for (int i = 1; i <= 200000; i++) {
    v.push_back({freq[i], i});
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (ch[v[i].second] || v[i].first == 0) continue;
    now = v[0].second;
    ubah(l[now], r[now], now);
  }
  cout << ans << endl;
}
