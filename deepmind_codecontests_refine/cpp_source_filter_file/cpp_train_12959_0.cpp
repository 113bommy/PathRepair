#include <bits/stdc++.h>
using namespace std;
int dist[551000];
long long int sum = 0;
set<long long int> ans;
int fTemp[551000];
int freq[551000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> dist[i + 1];
    if (i + 1 >= 2) {
      dist[i] = dist[i + 1] - dist[i];
      sum += dist[i];
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int p;
    cin >> p;
    freq[p]++;
  }
  int dir = 1;
  int stop = 1;
  int end = -1;
  set<int> good;
  long long int d = 0;
  for (int i = 0; i < m; i++) {
    fTemp[stop]++;
    if (i == m - 1) {
      end = stop;
      break;
    }
    if (stop + dir <= n && stop + dir >= 1) {
      d += dist[((stop > stop + dir) ? stop + dir : stop)];
      stop += dir;
    }
    if (stop == n)
      dir = -1;
    else if (stop == 1)
      dir = 1;
  }
  for (int i = 1; i < n + 1; i++) {
    if (fTemp[i] == freq[i]) good.insert(i);
  }
  if (good.size() == n) {
    ans.insert(d);
  }
  if (end == n)
    dir = -1;
  else if (end == 1)
    dir = -1;
  for (int i = 2; i < n + 1; i++) {
    fTemp[i - 1]--;
    d -= dist[i - 1];
    if (end == n) {
      dir = -1;
    } else if (end == 1) {
      dir = 1;
    }
    fTemp[end + dir]++;
    d += dist[((end + dir > end) ? end : end + dir)];
    if (fTemp[i - 1] == freq[i - 1])
      good.insert(i - 1);
    else {
      good.erase(i - 1);
    }
    if (fTemp[end + dir] == freq[end + dir])
      good.insert(end + dir);
    else {
      good.erase(end + dir);
    }
    if (good.size() == n) {
      ans.insert(d);
    }
    end += dir;
  }
  if (end == n)
    dir = -1;
  else if (end == 1)
    dir = -1;
  for (int i = n - 1; i > 1; i--) {
    fTemp[i + 1]--;
    d -= dist[i];
    if (end == n) {
      dir = -1;
    } else if (end == 1) {
      dir = 1;
    }
    fTemp[end + dir]++;
    d += dist[((end + dir > end) ? end : end + dir)];
    if (fTemp[i - 1] == freq[i - 1])
      good.insert(i - 1);
    else {
      good.erase(i - 1);
    }
    if (fTemp[end + dir] == freq[end + dir])
      good.insert(end + dir);
    else {
      good.erase(end + dir);
    }
    if (good.size() == n) {
      ans.insert(d);
    }
    end += dir;
  }
  if (ans.size() > 1) {
    cout << -1;
  } else {
    cout << *ans.begin();
  }
  return 0;
}
