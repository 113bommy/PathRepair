#include <bits/stdc++.h>
using namespace std;
int* num;
struct ka {
  int v = 1;
  vector<int> next;
};
int* used;
void rec(ka* a, int v) {
  used[v] = 1;
  if (a[v].next.size() == 1 && used[a[v].next[0]]) {
    num[v] = 1;
    return;
  }
  for (int i = 0; i < a[v].next.size(); i++) {
    if (!used[a[v].next[i]]) {
      rec(a, a[v].next[i]);
      num[v] += num[a[v].next[i]];
    }
  }
}
int main() {
  int n, x;
  cin >> n;
  used = (int*)calloc(n, sizeof(int));
  ka* a = (ka*)calloc(n, sizeof(ka));
  num = (int*)calloc(n + 1, sizeof(int));
  for (int i = 1; i < n; i++) {
    cin >> x;
    a[i].next.push_back(x - 1);
    a[x - 1].next.push_back(i);
  }
  if (n == 1) {
    cout << 1;
    return 0;
  }
  rec(a, 0);
  int* chetnost = (int*)calloc(n + 1, sizeof(int));
  for (int i = 0; i < n; i++) {
    chetnost[num[i]]++;
  }
  int cur = chetnost[1], lamps = 1;
  for (int i = 1; i <= n; i++) {
    if (i <= cur) {
      cout << lamps << " ";
    } else {
      lamps++;
      cur += chetnost[lamps];
      while (lamps <= n && cur < i) {
        lamps++;
        cur += chetnost[lamps];
      }
      cout << lamps << " ";
    }
  }
  return 0;
}
