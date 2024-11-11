#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)(1e5 + 10);
int n, m;
int arr[maxN];
map<int, int> cnt;
vector<int> vals;
pair<int, int> q[maxN];
int num[maxN], ans[maxN];
int main(int argc, char** argv) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] < maxN - 10) cnt[arr[i]]++;
  }
  for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
    if ((*it).first <= (*it).second) vals.push_back((*it).first);
  }
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    q[i] = pair<int, int>(a, b);
  }
  for (int i = 0; i < (int)vals.size(); i++) {
    for (int j = 0; j < n; j++) num[j + 1] = num[j] + (arr[j] == vals[i]);
    for (int j = 0; j < m; j++) {
      int l = q[j].first, r = q[j].second;
      if (num[r + 1] - num[l] == vals[i]) ans[j]++;
    }
  }
  for (int i = 0; i < m; i++) cout << ans[i] << '\n';
  return 0;
}
