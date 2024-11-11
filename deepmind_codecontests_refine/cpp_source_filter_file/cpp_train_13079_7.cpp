#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int mod = 1e9 + 7;
const int maxn = 5e5 + 100;
const int maxm = 2e3 + 100;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
long long n;
int k;
vector<int> v;
queue<int> q;
map<long long, int> num;
bool cmp(int a, int b) { return a > b; }
int main() {
  scanf("%lld %d", &n, &k);
  long long x = n;
  int cnt = 0;
  while (x) {
    if (x & 1) {
      v.push_back(cnt);
    }
    cnt++;
    x /= 2;
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < (int)v.size(); i++) {
    num[v[i]]++;
  }
  if (v.size() > k) {
    printf("No");
    return 0;
  } else {
    printf("Yes\n");
    int mx = v[0];
    int mi = v.back();
    int lst = k - v.size();
    while (lst) {
      if (lst >= num[mx]) {
        lst -= num[mx];
        num[mx - 1] += 2 * num[mx];
        num[mx] = 0;
        mx--;
        mi = min(mi, mx);
      } else {
        while (lst) {
          num[mi - 1]++;
          num[mi]--;
          mi--;
          lst--;
        }
      }
    }
    for (int i = mx; i >= mi; i--) {
      for (int j = 1; j <= num[i]; j++) {
        printf("%d ", i);
      }
    }
  }
  return 0;
}
