#include <bits/stdc++.h>
using namespace std;
bool fuckingGoodComp(pair<int, pair<int, int> > first,
                     pair<int, pair<int, int> > second) {
  return first.second.first < second.second.first;
}
void solve(vector<pair<int, pair<int, int> > > group, int sol[][2],
           const int width, const int height) {
  int pos = group.size();
  for (int i = 0; i < group.size(); i++) {
    if (group[i].second.first > group[i].second.second) {
      pos = i;
      break;
    }
  }
  int start = 0, startPos = pos;
  int posBack = pos - 1, fullBack = group.size() - 1;
  while (start < startPos && fullBack >= startPos) {
    sol[group[start].first][1] = group[pos].second.first;
    sol[group[start].first][0] = height;
    sol[group[fullBack].first][1] = width;
    sol[group[fullBack].first][0] = group[posBack].second.second;
    start++;
    pos++;
    posBack--;
    fullBack--;
  }
  int diff = start;
  while (start < startPos) {
    sol[group[start].first][0] = group[start - diff].second.second;
    sol[group[start].first][1] = width;
    start++;
  }
  diff = (group.size() - 1) - fullBack;
  while (fullBack >= startPos) {
    sol[group[fullBack].first][1] = group[fullBack + diff].second.first;
    sol[group[fullBack].first][0] = height;
    fullBack--;
  }
  if (group.size() == 1) {
    if (group[0].second.first <= 0) {
      sol[group[0].first][1] = width;
      sol[group[0].first][0] = group[0].second.second;
    } else {
      sol[group[0].first][1] = group[0].second.first;
      sol[group[0].first][0] = height;
    }
  }
}
int main() {
  map<int, int> sums;
  int n, in1, in2, in3, width, height;
  cin >> n >> height >> width;
  int solution[n][2];
  vector<pair<int, int> > cords;
  for (int i = 0; i < n; i++) {
    cin >> in1 >> in2 >> in3;
    cords.push_back(make_pair(in2, -in3));
    if (in1 == 1) swap(cords.back().first, cords.back().second);
    if (sums[in2 - in3] == 0) sums[in2 - in3] = sums.size();
  }
  vector<vector<pair<int, pair<int, int> > > > groups(sums.size());
  for (int i = 0; i < n; i++) {
    in1 = cords[i].first;
    in2 = cords[i].second;
    groups[sums[in1 + in2] - 1].push_back(make_pair(i, make_pair(in1, in2)));
  }
  for (int i = 0; i < groups.size(); i++)
    stable_sort(groups[i].begin(), groups[i].end(), fuckingGoodComp);
  for (int i = 0; i < groups.size(); i++) {
    solve(groups[i], solution, width, height);
  }
  for (int i = 0; i < n; i++) {
    cout << solution[i][0] << ' ' << solution[i][1] << '\n';
  }
  return 0;
}
