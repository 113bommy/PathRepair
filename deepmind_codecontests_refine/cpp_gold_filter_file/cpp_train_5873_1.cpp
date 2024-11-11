#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> hm;
vector<int> to;
vector<int> visited;
int hotel;
int main(int argc, char **argv) {
  scanf("%d", &n);
  for (int i = 0; i < 100000; i++) {
    to.push_back(0);
    visited.push_back(0);
  }
  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    if (temp == 1) hotel = i + 1;
    hm.push_back(temp);
  }
  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    if (temp != 0) {
      if (to[temp - 1] == 0)
        to[temp - 1] = i + 1;
      else
        to[temp - 1] = -1;
    }
  }
  vector<int> pathF;
  for (int i = 0; i < n; i++) {
    if (hm[i] == 0 && to[i] > 0 && visited[i] == 0) {
      vector<int> path;
      path.push_back(i + 1);
      int cycle = i;
      int t1 = i;
      int d = -1;
      visited[i] = 1;
      int found = 0;
      while (1) {
        d = to[t1] - 1;
        if (d == cycle) break;
        if (to[d] > 0) {
          path.push_back(d + 1);
          t1 = d;
          visited[d] = 1;
        } else {
          if (hm[d] == 1) {
            path.push_back(d + 1);
            found = 1;
          }
          break;
        }
      }
      if (found == 1 && path.size() > pathF.size()) pathF = path;
    }
  }
  if (pathF.size() > 1) {
    printf("%d\n", pathF.size());
    for (int i = 0; i < pathF.size(); i++) printf("%d ", pathF[i]);
  } else {
    printf("1\n%d", hotel);
  }
  return 0;
}
