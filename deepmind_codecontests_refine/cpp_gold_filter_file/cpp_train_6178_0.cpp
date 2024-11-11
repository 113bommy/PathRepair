#include <bits/stdc++.h>
using namespace std;
int main() {
  int clu, files;
  cin >> clu >> files;
  vector<int> clusters(clu + 1);
  int n;
  int cc = 0;
  int idx = 1;
  for (int i = 0; i < files; i++) {
    cin >> n;
    while (n--) {
      cin >> cc;
      clusters[cc] = idx++;
    }
  }
  vector<pair<int, int> > res;
  for (int i = 1; i < idx; i++) {
    int emptyC = 0;
    int currentPos = 0;
    for (int j = 1; j < (int)clusters.size(); j++) {
      if (!clusters[j]) {
        emptyC = j;
        break;
      }
    }
    for (int j = 1; j < (int)clusters.size(); j++) {
      if (clusters[j] == i) {
        currentPos = j;
        break;
      }
    }
    int actual = i;
    if (actual == currentPos) continue;
    if (actual != emptyC) res.push_back(make_pair(actual, emptyC));
    res.push_back(make_pair(currentPos, actual));
    clusters[currentPos] = 0;
    clusters[emptyC] = clusters[actual];
    clusters[actual] = actual;
  }
  cout << res.size() << endl;
  for (int i = 0; i < (int)res.size(); i++)
    cout << res[i].first << " " << res[i].second << endl;
  return 0;
}
