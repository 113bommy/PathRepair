#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 7;
const int M = 1e9;
const int inf = 1e9 + 7;
const long long base = 1e18;
const double pi = acos(-1);
const double ep = 1e-9;
int n, m, T;
deque<int> q;
int id[N];
int main() {
  int cnt = 0;
  scanf("%d%d%d", &n, &m, &T);
  bool check = false;
  for (int i = (int)0; i < (int)n; i++) {
    int A, B, C;
    scanf("%d:%d:%d", &A, &B, &C);
    int u = A * 3600 + B * 60 + C;
    while (!q.empty() && (q.front() < u)) q.pop_front();
    if (q.size() < m) {
      id[i] = ++cnt;
      q.push_back(u + T - 1);
    } else {
      q.front() = u + T - 1;
      id[i] = cnt;
    }
    if (q.size() == m) check = true;
  }
  if (check == false)
    puts("No solution");
  else {
    cout << cnt << endl;
    for (int i = (int)0; i < (int)n; i++) cout << id[i] << endl;
  }
}
