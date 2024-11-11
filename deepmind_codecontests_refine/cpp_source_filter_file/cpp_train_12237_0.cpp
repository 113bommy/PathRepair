#include <bits/stdc++.h>
using namespace std;
bool myfunction(int i, int j) { return (i > j); }
long long factorial[100001];
long long powe(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = powe(a, b / 2);
  temp *= temp;
  if (temp >= 1000000007) temp %= 1000000007;
  if (b % 2 == 1) temp *= a;
  if (temp >= 1000000007) temp %= 1000000007;
  return temp;
}
long long ncr(long a, long b) {
  long long term = factorial[a] * powe(factorial[b], 1000000005);
  if (term >= 1000000007) term %= 1000000007;
  term *= powe(factorial[a - b], 1000000005);
  if (term >= 1000000007) term %= 1000000007;
  return term;
}
bool myfun(int i, int j) { return i > j; }
char g[1000000][15];
int main() {
  vector<int> v;
  int n;
  scanf("%d", &n);
  int len = 0;
  char s[15];
  while (n--) {
    scanf("%s", s);
    if (s[0] == 'i') {
      int k;
      scanf("%d", &k);
      sprintf(g[len], "insert %d\n", k);
      len++;
      v.push_back(k);
      push_heap(v.begin(), v.end(), myfun);
    } else if (s[0] == 'r') {
      if (v.size() != 0) {
        pop_heap(v.begin(), v.end(), myfun);
        v.pop_back();
        sprintf(g[len], "removeMin\n");
        len++;
      } else {
        sprintf(g[len], "insert 1\n");
        len++;
        sprintf(g[len], "removeMin\n");
        len++;
      }
    } else {
      int k;
      scanf("%d", &k);
      while (1) {
        if (v.size() == 0 || v.front() > k) {
          sprintf(g[len], "insert %d\n", k);
          v.push_back(k);
          push_heap(v.begin(), v.end(), myfun);
          len++;
          sprintf(g[len], "getMin %d\n", k);
          len++;
          break;
        } else if (v.front() == k) {
          sprintf(g[len], "getMin %d\n", k);
          len++;
          break;
        } else {
          sprintf(g[len], "removeMin\n");
          len++;
          pop_heap(v.begin(), v.end(), myfun);
          v.pop_back();
        }
      }
    }
  }
  printf("%d\n", len);
  int i = 0;
  for (i = 0; i < len; i++) {
    printf("%s", g[i]);
  }
  return 0;
}
