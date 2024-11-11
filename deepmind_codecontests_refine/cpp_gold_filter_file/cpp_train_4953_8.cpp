#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  if (n < 4)
    printf("-1\n");
  else if (n == 4) {
    if (k != 3)
      printf("-1\n");
    else {
      printf("3\n");
      printf("1 2\n2 3\n3 4\n");
    }
  } else if (k == 3) {
    vector<pair<int, int> > vec;
    int ans = 0;
    if (n & 1) {
      ans = 5;
      vec.push_back(make_pair(1, 2));
      vec.push_back(make_pair(2, 3));
      vec.push_back(make_pair(2, 4));
      vec.push_back(make_pair(3, 5));
      vec.push_back(make_pair(4, 5));
      for (int i = 6; i <= n; i++) {
        if (!(i & 1)) {
          vec.push_back(make_pair(1, i));
          ans++;
        } else {
          for (int j = 2; j < i; j++) {
            vec.push_back(make_pair(j, i));
            ans++;
          }
        }
      }
    } else {
      ans = 3;
      vec.push_back(make_pair(1, 2));
      vec.push_back(make_pair(2, 3));
      vec.push_back(make_pair(3, 4));
      for (int i = 5; i <= n; i++) {
        if (i & 1) {
          vec.push_back(make_pair(1, i));
          ans++;
        } else {
          for (int j = 2; j < i; j++) {
            vec.push_back(make_pair(j, i));
            ans++;
          }
        }
      }
    }
    printf("%d\n", ans);
    for (auto& p : vec) {
      printf("%d %d\n", p.first, p.second);
    }
  } else if (k == 2) {
    printf("%d\n", n - 1);
    for (int i = 1; i < n; i++) {
      printf("%d %d\n", i, i + 1);
    }
  } else {
    printf("-1\n");
  }
}
