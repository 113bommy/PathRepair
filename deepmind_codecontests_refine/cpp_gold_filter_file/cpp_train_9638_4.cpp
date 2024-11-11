#include <bits/stdc++.h>
using namespace std;
const int N = 2200;
int c[N];
vector<int> vec;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", c + i);
  if (n == 1) {
    return puts("a"), 0;
  }
  int k = c[2] - c[1];
  for (int i = 3; i <= n + 2; i++) {
    int d1 = c[i - 2] - c[i - 1], d2 = c[i - 1] - c[i];
    int d = d1 - d2;
    while (d--) vec.push_back(i - 2);
  }
  for (int i = 0; i < vec.size(); i++)
    for (int j = 0; j < vec[i]; j++) printf("%c", 'a' + i % 2);
  return 0;
}
