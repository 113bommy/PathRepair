#include <bits/stdc++.h>
using namespace std;
template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T> > {};
map<int, int> p;
int k;
int prec[] = {0, 1, 0, 1, 2, 0, 2};
int solve(int x) {
  if (x < 7) return prec[x];
  if (x % 2 == 1) return 0;
  set<int> s;
  for (int i = 0; i < 3; ++i) s.insert(i);
  s.erase(solve(x - 1));
  s.erase(solve(x / 2));
  return *s.begin();
}
int main(void) {
  int n, k;
  scanf("%d%d", &n, &k);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (k % 2 == 0)
      ans ^= x < 3 ? x : (x % 2 == 0 ? 1 : 0);
    else
      ans ^= solve(x);
  }
  if (ans)
    puts("Kevin");
  else
    puts("Nicky");
}
