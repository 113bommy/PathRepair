#include <bits/stdc++.h>
using namespace std;
int n, v, pre1[100009], pre2[100009];
vector<pair<int, int> > a, b;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> v;
  int sum1 = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    sum1 += y;
    if (x == 1)
      a.push_back({y, i});
    else
      b.push_back({y, i});
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int s1 = a.size(), s2 = b.size();
  for (int i = 0; i < s1; i++) {
    if (i == 0)
      pre1[i] = a[i].first;
    else
      pre1[i] = pre1[i - 1] + a[i].first;
  }
  for (int i = 0; i < s2; i++) {
    if (i == 0)
      pre2[i] = b[i].first;
    else
      pre2[i] = pre2[i - 1] + b[i].first;
  }
  int space2, space1 = 0, cap = 0;
  for (int i = 1; i <= s1; i++) {
    int sp = v - i;
    if (sp >= 0) {
      int rem = sp / 2;
      rem = min(s2, rem);
      int sum1 = pre1[i - 1] + pre2[rem - 1];
      if (cap < sum1) {
        cap = sum1;
        space1 = i;
        space2 = rem;
      }
    }
  }
  for (int i = 1; i <= s2; i++) {
    int sp = v - 2 * i;
    if (sp >= 0) {
      int rem = sp;
      rem = min(s1, rem);
      int sum1 = pre2[i - 1] + pre1[rem - 1];
      if (cap < sum1) {
        cap = sum1;
        space1 = rem;
        space2 = i;
      }
    }
  }
  cout << cap << "\n";
  for (int i = 0; i < space1; i++) cout << a[i].second << " ";
  for (int i = 0; i < space2; i++) cout << b[i].second << " ";
  return 0;
}
