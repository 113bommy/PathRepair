#include <bits/stdc++.h>
using namespace std;
int a = 0, k, m;
set<int> res;
int head;
void generate(int v, int rem) {
  if (rem == 0) {
    int dif = abs(abs(v) - k);
    if (dif < 10000) {
      if (res.size() < m) res.insert(dif + head * 10000);
      if (res.size() < m) res.insert(dif * 10000 + head);
    }
    return;
  }
  generate(v + rem % 10, rem / 10);
  generate(v - rem % 10, rem / 10);
  generate(v * (rem % 10), rem / 10);
}
int main() {
  scanf("%d%d", &k, &m);
  int first = k, second = 0;
  for (int i = 0; i < 10000; ++i) {
    head = i;
    generate(i % 10, i / 10);
  }
  for (set<int>::iterator i = res.begin(); i != res.end(); ++i)
    printf("%08d\n", *i);
  return 0;
}
