#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> num[1100];
int bsearch(int i, int key) {
  int left = 0, right = num[i].size(), mid;
  while (left <= right) {
    mid = left + right >> 1;
    if (num[i][mid] == key)
      return mid;
    else if (num[i][mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return left;
}
int main() {
  scanf("%d", &n);
  int m, t;
  for (int i = 0; i < n; i++) {
    scanf("%d", &m);
    num[i].clear();
    for (int j = 0; j < m; j++) {
      scanf("%d", &t);
      num[i].push_back(t);
    }
    sort(num[i].begin(), num[i].end());
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 1; j < num[i].size(); j++) {
      int l = (i + n - 1) % n, r = (i + 1) % n;
      int left = bsearch(l, num[i][j]) - bsearch(l, num[i][j - 1]);
      int right = bsearch(r, num[i][j]) - bsearch(r, num[i][j - 1]);
      if (left != right) cnt++;
    }
  printf("%d\n", cnt);
  return 0;
}
