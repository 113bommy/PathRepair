#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, m;
  cin >> n >> m;
  vector<vector<std::pair<long long, string> > > scores(m);
  for (long i = 0; i < n; i++) {
    string name;
    long region;
    long score;
    cin >> name >> region >> score;
    scores[region - 1].push_back(std::pair<long, std::string>(score, name));
  }
  for (long j = 0; j < m; j++) {
    sort(scores[j].begin(), scores[j].end());
    int n = scores[j].size();
    if (scores[j].size() > 2 &&
        scores[j][n - 3].first >= scores[j][n - 2].first) {
      cout << "?" << endl;
      continue;
    } else {
      cout << scores[j][n - 1].second << " " << scores[j][n - 2].second << endl;
    }
  }
  return 0;
}
