#include <bits/stdc++.h>
using namespace std;
int n, a[100001], x[100001], sump, sumn, ans, ps = 1, ng = 1, sumr;
int main() {
  pair<int, int> pos[100001], neg[10001];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> a[i];
    if (x[i] < 0) {
      neg[ng] = make_pair(x[i], a[i]);
      ng++;
    } else if (x[i] > 0) {
      pos[ps] = make_pair(x[i], a[i]);
      ps++;
    }
    sumr += a[i];
  }
  sort(neg + 1, neg + ng);
  sort(pos + 1, pos + ps);
  if (ng == ps) {
    cout << sumr;
    return 0;
  } else if (ps < ng) {
    for (int i = 1; i <= ps; i++) ans += neg[i].second;
    for (int i = 1; i <= ps - 1; i++) ans += pos[i].second;
    cout << ans;
    return 0;
  } else {
    for (int i = 1; i <= ng; i++) ans += pos[i].second;
    for (int i = 1; i <= ng - 1; i++) ans += neg[i].second;
    cout << ans;
    return 0;
  }
  return 0;
}
