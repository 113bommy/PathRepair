#include <bits/stdc++.h>
std::set<int> s;
std::vector<bool> wh;
bool push(int n) {
  for (int it = 1; it < 32; ++it) {
    if (!wh[n >> it]) {
      s.erase(n);
      wh[n] = false;
      s.insert(n >> it);
      wh[n >> it] = true;
      return true;
    }
  }
  return false;
}
void solution() {
  int n, temp;
  scanf("%d", &n);
  wh.resize(1000000001, false);
  wh[0] = true;
  while (n-- > 0) {
    scanf("%d", &temp);
    s.insert(temp);
    wh[temp] = true;
  }
  while (push(*s.begin()))
    ;
  for (auto it : s) {
    printf("%d ", it);
  }
}
int main() {
  solution();
  return 0;
}
