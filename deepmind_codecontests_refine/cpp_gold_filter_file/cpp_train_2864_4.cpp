#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int arr[maxn];
long long diff[maxn];
int n, q;
void stvori_diff(int l, int r) {
  for (int i = 0; i < r - l + 1; i++) {
    diff[i] = abs(arr[i + l + 1] - arr[i + l]);
  }
}
int manji_lijevo[maxn];
int manji_jednak_desno[maxn];
stack<pair<int, int> > s;
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    stvori_diff(l, r);
    int d = r - l + 1;
    while (!s.empty()) s.pop();
    for (int i = 0; i < d - 1; i++) {
      manji_lijevo[i] = 0;
      while (!s.empty() and s.top().first < diff[i]) {
        s.pop();
      }
      if (s.empty())
        manji_lijevo[i] = i;
      else
        manji_lijevo[i] = i - s.top().second - 1;
      s.push(pair<int, int>(diff[i], i));
    }
    while (!s.empty()) s.pop();
    for (int i = d - 2; i >= 0; i--) {
      manji_jednak_desno[i] = 0;
      while (!s.empty() and s.top().first <= diff[i]) {
        s.pop();
      }
      if (s.empty())
        manji_jednak_desno[i] = d - 2 - i;
      else
        manji_jednak_desno[i] = s.top().second - i - 1;
      s.push(pair<int, int>(diff[i], i));
    }
    long long ans = 0;
    for (int i = 0; i < d - 1; i++) {
      ans += diff[i];
      ans += diff[i] * manji_jednak_desno[i];
      ans += diff[i] * manji_lijevo[i];
      ans += diff[i] * manji_jednak_desno[i] * manji_lijevo[i];
    }
    cout << ans << endl;
  }
  return 0;
}
