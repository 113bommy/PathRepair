#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int ans[3000];
int main() {
  srand(time(NULL));
  int n;
  cin >> n;
  int st;
  while (1) {
    int a = rand() % n + 1, b = rand() % n + 1;
    while (a == b) b = rand() % n + 1;
    printf("? %d %d\n", a, b);
    cout.flush();
    int x;
    scanf("%d", &x);
    if (__builtin_popcount(x) < 8) {
      st = a;
      break;
    }
  }
  int MIN = 100000000;
  for (int i = 1; i <= n; i++)
    if (i != st) v.push_back(i);
  while (1) {
    vector<int> v1;
    int q = (1 << 20) - 1;
    for (auto p : v) {
      int a = st, b = p;
      printf("? %d %d\n", a, b);
      cout.flush();
      int x;
      scanf("%d", &x);
      q &= x;
      if (x < MIN) {
        MIN = x;
        v1.clear();
      }
      if (x == MIN) v1.push_back(p);
    }
    if (q == 0) break;
    if (v1.size() == 1) {
      st = v1.back();
      break;
    }
    st = v1.back();
    v1.pop_back();
    swap(v, v1);
  }
  for (int i = 1; i <= n; i++) {
    if (st == i)
      ans[i] = 0;
    else {
      printf("? %d %d\n", st, i);
      cout.flush();
      scanf("%d", &ans[i]);
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
