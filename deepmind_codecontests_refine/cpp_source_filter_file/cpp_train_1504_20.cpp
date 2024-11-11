#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
int d() {
  int ret;
  scanf("%d", &ret);
  return ret;
}
long long lld() {
  long long ret;
  scanf("%lld", &ret);
  return ret;
}
bool cmp(pair<int, int> s, pair<int, int> f) {
  if (f.first > s.first)
    return true;
  else if (f.first == f.second && f.second < s.second)
    return true;
  else
    return false;
}
char arr[4];
char arr1[4];
int main() {
  int n = d(), lo = -1e9, hi = 1e9;
  while (n--) {
    scanf("%s", arr);
    int x = d();
    scanf("%s", arr1);
    if (arr[0] == '>' && arr[1] == '=') {
      if (arr1[0] == 'Y') {
        lo = max(lo, x);
      } else {
        hi = min(hi, x - 1);
      }
    } else if (arr[0] == '>') {
      if (arr1[0] == 'Y') {
        lo = max(lo, x + 1);
      } else {
        hi = min(hi, x);
      }
    } else if (arr[0] == '<' && arr[1] == '=') {
      if (arr1[0] == 'Y') {
        hi = min(x, hi);
      } else {
        lo = max(lo, x + 1);
      }
    } else if (arr[0] == '<') {
      if (arr1[0] == 'Y') {
        hi = min(x - 1, hi);
      } else {
        lo = max(lo, x);
      }
    }
  }
  if (lo > hi) {
    printf("Impossible\n");
    return 0;
  }
  printf("%d\n", lo);
}
