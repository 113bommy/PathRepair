#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n, c, d;
  cin >> n >> c >> d;
  vector<pair<int, int> > vec1, vec2;
  int i;
  for (i = 0; i < n; i++) {
    int be, cost;
    char type;
    cin >> be >> cost >> type;
    if (type == 'C') vec1.push_back(make_pair(cost, be));
    if (type == 'D') vec2.push_back(make_pair(cost, be));
  }
  sort(vec1.begin(), vec1.end());
  sort(vec2.begin(), vec2.end());
  int s1 = vec1.size();
  int s2 = vec2.size();
  vector<int> maxbc(s1), maxbc2(s1), maxbd(s2), maxbd2(s2);
  int max = 0, nextmax = 0;
  for (i = 0; i < s1; i++) {
    if (max < vec1[i].second) {
      nextmax = max;
      max = vec1[i].second;
    } else if (nextmax < vec1[i].second) {
      nextmax = vec1[i].second;
    }
    maxbc[i] = max;
    maxbc2[i] = nextmax;
  }
  max = 0, nextmax = 0;
  for (i = 0; i < s2; i++) {
    if (max < vec2[i].second) {
      nextmax = max;
      max = vec2[i].second;
    } else if (nextmax < vec2[i].second) {
      nextmax = vec2[i].second;
    }
    maxbd[i] = max;
    maxbd2[i] = nextmax;
  }
  int ans = 0;
  int coins = c;
  int maxbe = 0;
  for (i = 0; i < s1; i++) {
    int left = coins - vec1[i].first;
    vector<pair<int, int> >::iterator it =
        upper_bound(vec1.begin(), vec1.end(), make_pair(left, INT_MAX));
    it--;
    int loc = it - vec1.begin();
    if (loc == 0 && i == 0) continue;
    if (loc != -1) {
      int bee = maxbc[loc];
      if (bee == vec1[i].second) bee = maxbc2[loc];
      if (maxbe < vec1[i].second + bee) {
        maxbe = vec1[i].second + bee;
      }
    }
  }
  if (ans < maxbe) ans = maxbe;
  int diams = d;
  maxbe = 0;
  for (i = 0; i < s2; i++) {
    int left = diams - vec2[i].first;
    vector<pair<int, int> >::iterator it =
        upper_bound(vec2.begin(), vec2.end(), make_pair(left, 0));
    it--;
    int loc = it - vec2.begin();
    if (loc == 0 && i == 0) continue;
    if (loc != -1) {
      int bee = maxbd[loc];
      if (bee == vec2[i].second) bee = maxbd2[loc];
      if (maxbe < vec2[i].second + bee) {
        maxbe = vec2[i].second + bee;
      }
    }
  }
  if (ans < maxbe) ans = maxbe;
  maxbe = 0;
  for (i = 0; i < s1; i++) {
    if (vec1[i].first > c) break;
  }
  int maxcc = i - 1;
  for (i = 0; i < s2; i++) {
    if (vec2[i].first > d) break;
  }
  int maxdd = i - 1;
  if (maxcc != -1 && maxdd != -1) {
    maxbe = maxbc[maxcc] + maxbd[maxdd];
  }
  if (ans < maxbe) ans = maxbe;
  cout << ans;
  return 0;
}
