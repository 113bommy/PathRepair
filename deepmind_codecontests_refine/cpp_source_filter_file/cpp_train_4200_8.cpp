#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  vector<pair<int, int> > answer;
  int soldiers, vests, x, y;
  cin >> soldiers >> vests >> x >> y;
  int soldiers_sizes[soldiers];
  long long vest_sizes[vests];
  for (int i = 0; i < soldiers; i++) {
    cin >> soldiers_sizes[i];
  }
  for (int i = 0; i < vests; i++) {
    cin >> vest_sizes[i];
  }
  int soldiers_pointer = 0;
  int vests_pointer = 0;
  int index = -2;
  int s = 0;
  int start, ending;
  for (int z = 0; z < vests; z++) {
    start = s;
    ending = vests - 1;
    index = -2;
    while (start <= ending) {
      int middle = start + (ending - start) / 2;
      long long down = soldiers_sizes[middle] - x;
      long long up = soldiers_sizes[middle] + y;
      if (vest_sizes[z] >= down && vest_sizes[z] <= up) {
        index = middle;
        ending = middle - 1;
      } else if (vest_sizes[z] < down) {
        ending = middle - 1;
      } else {
        start = middle + 1;
      }
    }
    if (index != -2) {
      answer.push_back(make_pair(index + 1, z + 1));
      s = index + 1;
    }
  }
  cout << answer.size() << '\n';
  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i].first << ' ' << answer[i].second << '\n';
  }
  return 0;
}
