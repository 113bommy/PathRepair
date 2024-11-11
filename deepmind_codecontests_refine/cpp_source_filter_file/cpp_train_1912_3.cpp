#include <bits/stdc++.h>
using namespace std;
int d[101][10001];
int main() {
  int n, m;
  string s;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    int pos = s.find('1');
    if (pos == string::npos) {
      cout << "-1\n";
      return 0;
    }
    int dist = 0;
    for (int j = 0; j < m; j++) {
      if (s[(pos + j) % m] == '1')
        dist = 0;
      else
        dist++;
      d[i][(j + pos) % m] = dist;
    }
    dist = 0;
    for (int j = m; j > 0; j--) {
      if (s[(pos + j) % m] == '1')
        dist = 0;
      else
        dist++;
      d[i][(j + pos) % m] =
          (dist > d[i][(j + pos) % m] ? dist : d[i][(j + pos) % m]);
    }
  }
  int ret = (int)1e9, sum;
  for (int j = 0; j < m; j++) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += d[i][j];
    }
    ret = (ret < sum ? ret : sum);
  }
  cout << ret << endl;
  return 0;
}
