#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 500;
int n, m1, m2, u, v;
int sup[3][N];
vector<pair<int, int> > ans;
inline long long gcd(long long a, long long b) {
  return b > 0 ? gcd(b, a % b) : a;
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
inline long long read() {
  long long ans = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return ans;
}
int find(int x, int num) {
  return sup[num][x] == x ? x : sup[num][x] = find(sup[num][x], num);
}
void join(int x, int y, int num) {
  int supx = find(x, num);
  int supy = find(y, num);
  if (supx < supy) sup[num][supy] = supx;
  if (supx > supy) sup[num][supx] = supy;
}
void show() {
  cout << "forest1:" << endl;
  for (int i = 1; i <= n; i++) cout << i << " " << sup[1][i] << "\n";
  cout << "forest2:" << endl;
  for (int i = 1; i <= n; i++) cout << i << " " << sup[2][i] << "\n";
}
int main() {
  n = read();
  m1 = read();
  m2 = read();
  for (int i = 1; i <= n; i++) sup[1][i] = sup[2][i] = i;
  for (int i = 1; i <= m1; i++) {
    u = read();
    v = read();
    join(u, v, 1);
  }
  for (int i = 1; i <= m2; i++) {
    u = read();
    v = read();
    join(u, v, 2);
  }
  for (int i = 2; i <= n; i++) {
    if (find(i, 1) != 1 && find(i, 2) != 1) {
      join(1, i, 1);
      join(1, i, 2);
      ans.push_back(make_pair(1, i));
    }
  }
  for (int i = 2, j = 2; i <= n; i++) {
    if (find(i, 1) != 1) {
      while (j < n && find(j, 2) == 1) j++;
      if (j == n) break;
      join(i, 1, 1);
      join(j, 1, 2);
      ans.push_back(make_pair(i, j));
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
}
