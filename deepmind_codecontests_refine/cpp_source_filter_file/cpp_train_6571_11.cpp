#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  vector<pair<int, int> > v, re;
  scanf("%d %d ", &a, &b);
  v.push_back(make_pair(a, b));
  scanf("%d %d ", &a, &b);
  v.push_back(make_pair(a, b));
  scanf("%d %d ", &a, &b);
  v.push_back(make_pair(a, b));
  sort(v.begin(), v.end());
  pair<int, int> A = v[0], B = v[1], C = v[2];
  int x = A.first, y = A.second;
  re.push_back(make_pair(x, y));
  if (C.second > A.second) {
    int dy = max(min(B.second, C.second), A.second);
    for (int i = A.second + 1; i <= dy; i++) {
      re.push_back(make_pair(x, i));
    }
    y += dy;
    for (int i = A.first + 1; i <= C.first; i++) {
      re.push_back(make_pair(i, y));
    }
    x = C.first;
    for (int i = y + 1; i <= C.second; i++) {
      re.push_back(make_pair(x, i));
    }
  } else {
    int dy = min(max(B.second, C.second), A.second);
    for (int i = A.second - 1; i >= dy; i--) {
      re.push_back(make_pair(x, i));
    }
    y = dy;
    for (int i = A.first + 1; i <= C.first; i++) {
      re.push_back(make_pair(i, y));
    }
    x = C.first;
    for (int i = y - 1; i >= C.second; i--) {
      re.push_back(make_pair(x, i));
    }
  }
  if (B.second > y) {
    for (int i = y + 1; i <= B.second; i++) {
      re.push_back(make_pair(B.first, i));
    }
  } else {
    for (int i = y - 1; i >= B.second; i--) {
      re.push_back(make_pair(B.first, i));
    }
  }
  printf("%d\n", re.size());
  for (int i = 0; i < re.size(); i++) {
    printf("%d %d\n", re[i].first, re[i].second);
  }
}
