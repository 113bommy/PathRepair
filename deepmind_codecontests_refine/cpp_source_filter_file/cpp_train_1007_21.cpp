#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int c[100000], h[10], fc[100000], k;
long long mem[500][5000];
long long solve(int pos, int rem) {
  if (pos == 0) return 0;
  if (mem[pos][rem] != -1) return mem[pos][rem];
  long long ans = 0;
  for (int i = 1; i <= rem && i <= k; i++) {
    long long cur = h[i - 1] + solve(pos - 1, rem - i);
    if (cur > ans) ans = cur;
  }
  return mem[pos][rem] = ans;
}
int main() {
  int n;
  cin >> n >> k;
  for (int i = 0; i < n * k; i++) {
    int cc;
    cin >> cc;
    c[cc - 1]++;
  }
  set<int> favourites;
  for (int i = 0; i < n; i++) {
    int ff;
    cin >> ff;
    ff--;
    fc[ff]++;
    favourites.insert(ff);
  }
  for (int i = 0; i < k; i++) {
    cin >> h[i];
  }
  long long ans = 0;
  memset(mem, -1, sizeof(mem));
  for (auto& ff : favourites) {
    long long cur = solve(fc[ff], c[ff]);
    ans += cur;
  }
  cout << ans << endl;
  return 0;
}
