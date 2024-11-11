#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, bool> mp;
map<pair<pair<int, int>, pair<int, int> >, bool> mp1;
map<pair<int, int>, bool>::iterator it;
map<pair<pair<int, int>, pair<int, int> >, bool>::iterator it1;
map<pair<pair<int, int>, pair<int, int> >, bool>::iterator it2;
pair<int, int> arr[4];
int xx, yy, xx1, yy1;
int main() {
  for (int i = 0; i < 4; i++) {
    scanf("%d %d %d %d", &xx, &yy, &xx1, &yy1);
    if ((xx - xx1 != 0 && yy - yy1 != 0) || (hypot(xx - xx1, yy - yy1) == 0)) {
      puts("NO");
      return 0;
    }
    it1 = mp1.find(make_pair(pair<int, int>(xx, yy), pair<int, int>(xx1, yy1)));
    it2 = mp1.find(make_pair(pair<int, int>(xx1, yy1), pair<int, int>(xx, yy)));
    if (it1 != mp1.end() || it2 != mp1.end()) {
      puts("NO");
      return 0;
    }
    mp1[make_pair(pair<int, int>(xx, yy), pair<int, int>(xx1, yy1))] = 1;
    mp1[make_pair(pair<int, int>(xx1, yy1), pair<int, int>(xx, yy))] = 1;
    it = mp.find(pair<int, int>(xx, yy));
    if (it == mp.end()) mp[pair<int, int>(xx, yy)] = 1;
    it = mp.find(pair<int, int>(xx1, yy1));
    if (it == mp.end()) mp[pair<int, int>(xx1, yy1)] = 1;
  }
  if (mp.size() == 4) {
    int i = 0;
    for (it = mp.begin(); it != mp.end(); it++, i++) arr[i] = it->first;
    sort(arr, arr + 4);
    if (arr[0].second == arr[2].second && arr[1].second == arr[3].second &&
        arr[0].first == arr[1].first && arr[2].first == arr[3].first)
      puts("YES");
    else
      puts("NO");
    return 0;
  }
  puts("NO");
  return 0;
}
