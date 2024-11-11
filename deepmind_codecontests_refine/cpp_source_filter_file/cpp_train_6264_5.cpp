#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int INFint = 1000000100;
const long long int INFll = 2000000000001000000;
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    a.push_back({tmp, i});
  }
  sort(a.begin(), a.end());
  int ni = a.back().second;
  int li = 1, ri = 1;
  a.pop_back();
  bool flag = false;
  while (!a.empty()) {
    flag = false;
    int ab = a.back().second;
    if (ab > ni) {
      if (ab - ri <= ni) {
        a.pop_back();
        ri++;
        flag = true;
      }
    }
    if (ab < ni) {
      if (ab + li >= ni) {
        a.pop_back();
        li++;
        flag = true;
      }
    }
    if (!flag) {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
  return 0;
}
