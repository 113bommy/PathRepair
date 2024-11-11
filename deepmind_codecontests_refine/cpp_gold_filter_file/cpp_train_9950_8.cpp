#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long llinf = 1ll * inf * inf;
const double eps = 1e-12;
int main() {
  string a, b;
  cin >> a >> b;
  vector<int> loc;
  for (int i = 0, j = 0; i < b.size(); ++i) {
    while (j < a.size() && a[j] != b[i]) ++j;
    if (j == a.size()) break;
    loc.push_back(j);
    j++;
  }
  int ansl = loc.size(), ansr = b.size() - 1;
  int lasti = b.size();
  for (int i = b.size() - 1, j = a.size() - 1; i >= 0; --i) {
    while (j >= 0 && a[j] != b[i]) --j;
    if (j == -1) break;
    lasti = i;
    j--;
  }
  if (ansr - ansl > lasti - 1 - 0) ansr = lasti - 1, ansl = 0;
  int locidx = loc.size() - 1;
  for (int i = b.size() - 1, j = a.size() - 1; i >= 0; --i) {
    while (j >= 0 && a[j] != b[i]) --j;
    if (j < 0) break;
    while (locidx >= 0 && loc[locidx] >= j) --locidx;
    int l = locidx + 1;
    int r = i - 1;
    if (r - l < ansr - ansl) ansl = l, ansr = r;
    if (locidx < 0) break;
    j--;
  }
  string ans = "";
  if (ansl == 0 && ansr == b.size() - 1)
    ans = "-";
  else if (ansl <= ansr)
    ans = string(b.begin(), b.begin() + ansl) +
          string(b.begin() + ansr + 1, b.end());
  else
    ans = b;
  cout << ans << endl;
  return 0;
}
