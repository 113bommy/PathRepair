#include <bits/stdc++.h>
using namespace std;
map<string, int> big;
vector<int> v;
int main() {
  char s[100];
  int n, x;
  scanf("%d", &n);
  while (n--) {
    scanf("%s %d", s, &x);
    big[s] = max(big[s], x);
  }
  n = ((int)(big).size());
  for (__typeof((big).begin()) it = (big).begin(); it != (big).end(); it++)
    v.push_back(it->second);
  sort(v.begin(), v.end());
  printf("%d\n", n);
  for (__typeof((big).begin()) it = (big).begin(); it != (big).end(); it++) {
    x = (it->second);
    int r = n - (upper_bound(v.begin(), v.end(), x) - v.begin());
    if (2 * r >= n)
      printf("%s noob", (it->first).c_str());
    else if (5 * r > n)
      printf("%s random", (it->first).c_str());
    else if (10 * r > n)
      printf("%s average", (it->first).c_str());
    else if (100 * r > n)
      printf("%s hardwore", (it->first).c_str());
    else
      printf("%s pro", (it->first).c_str());
    puts("");
  }
  return 0;
}
