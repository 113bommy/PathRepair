#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[100006];
int main() {
  map<int, vector<pair<int, int> > > mymap;
  int n;
  scanf("%d", &n);
  int i;
  int dif1[n], dif2[n], dif[n];
  for (i = 0; i < n; i++) {
    scanf("%d%d", &arr[i].first, &arr[i].second);
    dif1[i] = arr[i].second - arr[i].first;
    mymap[dif1[i]].push_back(arr[i]);
  }
  sort(arr, arr + n);
  for (i = 0; i < n; i++) {
    scanf("%d", &dif2[i]);
    dif[i] = dif2[i];
  }
  sort(dif1, dif1 + n);
  sort(dif, dif + n);
  int f = 0;
  for (i = 0; i < n; i++) {
    if (dif1[i] != dif[i]) {
      f = 1;
      break;
    }
  }
  if (f) {
    printf("NO\n");
    return 0;
  }
  map<int, vector<pair<int, int> > >::iterator it;
  for (it = mymap.begin(); it != mymap.end(); ++it)
    sort(mymap[it->first].begin(), mymap[it->first].end());
  int x = -1, y = -1;
  f = 0;
  for (i = 0; i < n; i++) {
    if (mymap[dif2[i]].size() == 0) {
      f = 1;
      break;
    } else {
      int x1 = mymap[dif2[i]][0].first, y1 = mymap[dif2[i]][0].second;
      mymap[dif2[i]].erase(mymap[dif2[i]].begin());
      if (x1 <= x && y1 <= y) {
        f = 1;
        break;
      }
      x = x1;
      y = y1;
      arr[i].first = x1;
      arr[i].second = y1;
    }
  }
  if (f) {
    printf("NO\n");
    return 0;
  } else {
    printf("YES\n");
    for (i = 0; i < n; i++)
      cout << arr[i].first << " " << arr[i].second << endl;
  }
  return 0;
}
