#include <bits/stdc++.h>
using namespace std;
int row, col;
long long int mx;
int dirx[] = {1, 0, -1, 0};
int diry[] = {0, 1, 0, -1};
int main() {
  long long int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<pair<long long int, long long int> > frst;
  int i;
  for (i = 0; i < n; i++) {
    long long int tmp;
    cin >> tmp;
    frst.push_back(make_pair(tmp, (i + 1)));
  }
  vector<pair<long long int, long long int> > scnd;
  for (i = 0; i < m; i++) {
    long long int tmp;
    cin >> tmp;
    scnd.push_back(make_pair(tmp, (i + 1)));
  }
  sort(frst.begin(), frst.end());
  sort(scnd.begin(), scnd.end());
  vector<pair<int, int> > res;
  int j = 0;
  i = 0;
  while (1) {
    if (i == n or j == m) break;
    long long int low = frst[i].first - x;
    long long int high = frst[i].first + y;
    if (scnd[j].first >= low and scnd[j].first <= high) {
      res.push_back(make_pair(frst[i].second, scnd[j].second));
      i++;
      j++;
    } else if (scnd[j].first > high) {
      i++;
    } else if (scnd[j].first < low) {
      j++;
    }
  }
  cout << res.size() << endl;
  for (i = 0; i < res.size(); i++) {
    cout << res[i].first << " " << res[i].second << endl;
  }
  return 0;
}
