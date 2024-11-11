#include <bits/stdc++.h>
using namespace std;
int n;
int a[3010];
vector<pair<int, int> > v;
int main() {
  while (cin >> n) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      int minv = a[i], minp = i;
      for (int j = i + 1; j <= n; j++) {
        if (minv > a[j]) {
          minv = a[j];
          minp = j;
        }
      }
      if (minp != i) {
        swap(a[i], a[minp]);
        cnt++;
        v.push_back(make_pair(i - 1, minp - 1));
      }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < v.size(); i++) {
      printf("%d %d\n", v[i].first, v[i].second);
    }
  }
  return 0;
}
