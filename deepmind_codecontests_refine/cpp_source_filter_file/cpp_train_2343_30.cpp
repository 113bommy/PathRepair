#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  int a[n];
  map<long long, int> cnt;
  for (int j = 0; j < n; ++j) {
    scanf("%d", &a[j]);
    cnt[a[j]]++;
  }
  int ans = 0;
  map<long long, int>::iterator it;
  while (cnt.size()) {
    it = cnt.begin();
    pair<long long, int> pr = (*it);
    if (pr.second == 0)
      cnt.erase(pr.first);
    else if (pr.second == 1) {
      ans++;
      cnt.erase(pr.first);
    } else {
      cnt[pr.first] -= 2;
      cnt[pr.first * 2]++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
