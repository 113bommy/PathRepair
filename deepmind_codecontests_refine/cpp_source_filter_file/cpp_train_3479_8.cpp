#include <bits/stdc++.h>
using namespace std;
int min(int x, int y) { return (x < y) ? x : y; }
int max(int x, int y) { return (x > y) ? x : y; }
int a[1000000] = {0}, n = 0, t = 0, x = 0;
char ch;
int main() {
  scanf("%d", &n);
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    m[x]++;
  }
  std::vector<int> v, k;
  int flag = 0;
  map<int, int>::iterator it = m.begin();
  while (1) {
    if (it->second > 1) {
      k.push_back(it->first);
      flag = 1;
    } else
      flag = 0;
    v.push_back(it->first);
    it++;
    if (it == m.end()) {
      if (flag == 1) k.pop_back();
      break;
    }
  }
  int len1 = v.size(), len2 = k.size();
  printf("%d\n", len1);
  for (int i = 0; i < len1; i++) printf("%d ", v[i]);
  for (int i = len2 - 1; i >= 0; i--) {
    printf("%d ", k[i]);
  }
  printf("\n");
  return 0;
}
