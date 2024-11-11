#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > ans;
const int MAXN = 25;
int a[MAXN];
int n;
void Go(int pos, int from, int help, int to, bool b) {
  if (pos == n) return;
  int tmp = pos;
  int val = a[pos];
  while (tmp < n && a[tmp] == val) tmp++;
  if (!b && tmp != pos + 1) {
    if (tmp == n) {
      for (int i = pos + 1; i < tmp; i++)
        ans.push_back(pair<int, int>(from, help));
      ans.push_back(pair<int, int>(from, to));
      for (int i = pos + 1; i < tmp; i++)
        ans.push_back(pair<int, int>(help, to));
    } else {
      Go(tmp, from, help, to, true);
      for (int i = pos; i < tmp; i++) ans.push_back(pair<int, int>(from, help));
      Go(tmp, to, help, from, true);
      for (int i = pos; i < tmp; i++) ans.push_back(pair<int, int>(help, to));
      Go(tmp, from, help, to, false);
    }
  } else {
    Go(tmp, from, to, help, true);
    for (int i = pos; i < tmp; i++) ans.push_back(pair<int, int>(from, to));
    Go(tmp, help, from, to, true);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  Go(0, 1, 2, 3, false);
  cout << (int)ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}
