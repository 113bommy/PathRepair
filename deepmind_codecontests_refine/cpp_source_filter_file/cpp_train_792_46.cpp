#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, a;
  cin >> n >> x;
  long long s = 0;
  char arr[105][105];
  bool repeated[105][105] = {0};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < x; j++) cin >> arr[i][j];
  map<char, pair<int, pair<int, int> > > mp, mp1;
  map<char, pair<int, pair<int, int> > >::iterator it, it1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < x; j++) {
      mp[arr[i][j]].first++;
      if (mp[arr[i][j]].first > 1) {
        repeated[i][j] = true;
        repeated[mp[arr[i][j]].second.first][mp[arr[i][j]].second.second] =
            true;
      }
      mp[arr[i][j]].second = {i, j};
    }
    mp.clear();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < x; j++) {
      mp1[arr[j][i]].first++;
      if (mp1[arr[j][i]].first > 1) {
        repeated[j][i] = true;
        repeated[mp1[arr[j][i]].second.first][mp1[arr[j][i]].second.second] =
            true;
      }
      mp1[arr[j][i]].second = {j, i};
    }
    mp1.clear();
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < x; j++)
      if (!repeated[i][j]) cout << arr[i][j];
  cout << endl;
  return 0;
}
