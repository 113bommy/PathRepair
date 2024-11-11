#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main() {
  scanf("%d", &n);
  while (n) {
    v.push_back(min(1, n));
    n -= v.back();
  }
  random_shuffle(v.begin(), v.end());
  printf("%d\n", (int)v.size());
  for (int i = 0; i < v.size(); i++)
    printf("%d%c", v[i], i == v.size() - 1 ? '\n' : ' ');
  return 0;
}
