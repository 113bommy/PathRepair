#include <bits/stdc++.h>
using namespace std;
const int inf = 100005;
pair<int, int> arr[inf];
pair<pair<int, int>, int> sa[4][inf];
int ans[inf];
int t[9];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) scanf("%d%d", &arr[i].first, &arr[i].second);
  for (int i = 0; i < m; i++) {
    sa[0][i].first.first = arr[i].first;
    sa[0][i].first.second = arr[i].second;
    sa[1][i].first.first = arr[i].second;
    sa[1][i].first.second = arr[i].first;
    sa[2][i].first.first = arr[i].first + arr[i].second;
    sa[2][i].first.second = arr[i].first;
    sa[3][i].first.first = abs(arr[i].first - arr[i].second);
    sa[3][i].first.second = arr[i].second;
    for (int j = 0; j < 4; j++) sa[j][i].second = i;
  }
  for (int i = 0; i < 4; i++) sort(sa[i], sa[i] + m);
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j < m; j++) {
      if (sa[i][j - 1].first.first == sa[i][j].first.first) {
        ans[sa[i][j - 1].second]++;
        ans[sa[i][j].second]++;
      }
    }
  }
  for (int i = 0; i < m; i++) t[ans[i]]++;
  for (int i = 0; i <= 8; i++) cout << t[i] << " ";
  cout << endl;
  return 0;
}
