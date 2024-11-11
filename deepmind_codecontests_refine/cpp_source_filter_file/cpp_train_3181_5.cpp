#include <bits/stdc++.h>
using namespace std;
int arr[200000];
vector<int> ret;
multiset<int> S;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  int r = 0, sz = 0;
  for (int i = 0; i < n; i++) {
    S.insert(arr[i]);
    while ((*S.rbegin()) - (*S.begin()) > k) {
      S.erase(arr[r++]);
    }
    if (S.size() > sz) {
      sz = S.size();
      ret.clear();
    }
    if (S.size() == sz) {
      ret.push_back(i);
    }
  }
  printf("%d %d\n", sz, ret.size());
  for (int i = 0; i < ret.size(); i++) {
    printf("%d %d\n", ret[i] - sz + 2, ret[i] + 1);
  }
  return 0;
}
