#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
int n, m;
string s;
int a[N];
int main() {
  cin >> n;
  int sum = 0;
  int d = 0;
  vector<int> p;
  vector<int> x;
  vector<int> q;
  vector<int> w;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], sum += a[i];
    if (a[i] == 1) p.push_back(i);
    if (a[i] >= 2) x.push_back(i);
  }
  if (p.size() > 2)
    d = x.size() + 2;
  else
    d = n;
  if (sum < (n - 1) * 2) {
    printf("NO\n");
    return 0;
  }
  printf("YES %d\n", d - 1);
  printf("%d\n", n - 1);
  if (p.size() == 0) {
    for (int i = 1; i < n; ++i) printf("%d %d\n", i, i + 1);
  } else if (p.size() == 1) {
    int ind = p[0];
    for (int i = 1; i < n; ++i) {
      printf("%d %d\n", (p[0] + i - 1) % n + 1, (p[0] + i) % n + 1);
    }
  } else {
    q.push_back(p[0]);
    for (int i = 0; i < x.size(); ++i) {
      q.push_back(x[i]);
      a[x[i]] -= 2;
    }
    q.push_back(p[1]);
    for (int i = 1; i < q.size(); ++i) printf("%d %d\n", q[i - 1], q[i]);
    int pos = 0;
    for (int i = 2; i < p.size(); ++i) {
      while (a[x[pos]] == 0) pos++;
      printf("%d %d\n", p[i], x[pos]);
      a[x[pos]]--;
    }
  }
  return 0;
}
