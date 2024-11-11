#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(200005, 0);
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    a[p]++;
  }
  int ans = 0, idx = -1;
  for (int i = 1; i <= 200002; i++) {
    if (!a[i]) continue;
    int cur = a[i], j = i + 1;
    while (a[j] > 1) {
      cur += a[j];
      j++;
    }
    if (a[j] == 1) cur += 1;
    if (ans < cur) {
      ans = cur;
      idx = i;
    }
    i = j;
  }
  cout << ans << endl;
  vector<int> tmp1, tmp2;
  int i = idx + 1;
  for (int j = 0; j < a[idx]; j++) tmp1.push_back(idx);
  for (; i <= 200002 && a[i] > 1; i++) {
    tmp1.push_back(i);
    for (int j = 0; j < a[i] - 1; j++) tmp2.push_back(i);
  }
  if (a[i] == 1) tmp1.push_back(i);
  reverse(tmp2.begin(), tmp2.end());
  for (int i = 0; i < tmp1.size(); i++) cout << tmp1[i] << " ";
  for (int i = 0; i < tmp2.size(); i++) cout << tmp2[i] << " ";
  cout << endl;
  return 0;
}
