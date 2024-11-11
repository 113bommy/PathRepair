#include <bits/stdc++.h>
using namespace std;
int main() {
  list<int> l;
  list<int>::iterator it;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) l.push_back(i);
  it = l.end();
  while (true) {
    l.insert(it, l.front());
    l.pop_front();
    --it;
    if (it == l.begin()) break;
    --it;
    if (it == l.begin()) break;
  }
  while (!l.empty()) {
    printf("%d ", l.front());
    l.pop_front();
  }
}
