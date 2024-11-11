#include <bits/stdc++.h>
using namespace std;
int n;
int p[10005];
int find(int x) {
  if (p[x] == x) return x;
  return p[x] = find(p[x]);
}
void join(int x, int y) {
  x = find(x);
  y = find(y);
  if (rand() % 2)
    p[x] = y;
  else
    p[y] = x;
}
int main() {
  cin >> n;
  int a;
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> a;
    join(a - 1, i);
  }
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(find(i));
  }
  cout << s.size();
  return 0;
}
