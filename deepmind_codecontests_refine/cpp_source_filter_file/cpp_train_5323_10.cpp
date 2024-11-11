#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void solve(int s) {
  while (s % 7 && s > 4) {
    s -= 4;
    ans.push_back(4);
  }
  while (s % 7 == 0 && s > 0) {
    s -= 7;
    ans.push_back(7);
  }
  if (s)
    puts("-1");
  else {
    for (int i = 0; i < ans.size(); i++) printf("%d", ans[i]);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  solve(n);
}
