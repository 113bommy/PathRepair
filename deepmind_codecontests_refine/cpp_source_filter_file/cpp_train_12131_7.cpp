#include <bits/stdc++.h>
using namespace std;
int n, k, a, len;
char s[200010];
long long ans;
vector<int> d[26];
inline int min(const int &a, const int &b) { return (a < b ? a : b); }
int binsearch(const int &index, const int &key) {
  int front = 0, back = d[index].size(), mid, ret;
  if (back == 0) return len;
  while (front < back) {
    mid = (back + front) >> 1;
    ret = min(ret, abs(d[index][mid] - key));
    if (d[index][mid] < key)
      front = mid + 1;
    else if (d[index][mid] > key)
      back = mid;
    else
      break;
  }
  return ret;
}
int main() {
  scanf("%d%d%s", &n, &k, &s);
  for (a = 0; a < k; ++a) d[s[a] - 'a'].push_back(a);
  while (n--) {
    scanf("%s", &s);
    len = strlen(s);
    ans = 0;
    for (a = 0; a < len; ++a) ans += binsearch(s[a] - 'a', a);
    printf("%d\n", ans);
  }
}
