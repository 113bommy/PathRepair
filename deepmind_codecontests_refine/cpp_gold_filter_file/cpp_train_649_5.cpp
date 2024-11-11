#include <bits/stdc++.h>
using namespace std;
string st;
int a[10], b[10], res;
vector<int> ra, rb;
int calc(int u) {
  if (a[u] == 0 || b[10 - u] == 0) return 0;
  a[u]--;
  b[10 - u]--;
  int s = 0;
  for (int i = 0; i < 10; i++) s += min(a[i], b[9 - i]);
  int temp1 = min(a[0], b[9]);
  int temp2 = min(b[0], a[9]);
  s += min(a[0] - temp1, b[0] - temp2);
  a[u]++;
  b[10 - u]++;
  return s + 1;
}
int main() {
  cin >> st;
  for (int i = 0; i < st.length(); i++) a[st[i] - '0']++;
  for (int i = 0; i < 10; i++) b[i] = a[i];
  res = min(a[0], b[0]);
  int s, id = -1;
  for (int i = 1; i < 10; i++) {
    s = calc(i);
    if (s > res) {
      res = s;
      id = i;
    }
  }
  if (id != -1) {
    a[id]--;
    b[10 - id]--;
    ra.push_back(id);
    rb.push_back(10 - id);
    for (int u = 0; u < 10; u++) {
      for (int i = 0; i < min(a[u], b[9 - u]); i++) {
        ra.push_back(u);
        rb.push_back(9 - u);
      }
      int temp = min(a[u], b[9 - u]);
      a[u] -= temp;
      b[9 - u] -= temp;
    }
  }
  int temp = min(a[0], b[0]);
  a[0] -= temp;
  b[0] -= temp;
  for (int u = 0; u < 10; u++)
    for (int i = 0; i < a[u]; i++) ra.push_back(u);
  for (int u = 0; u < 10; u++)
    for (int i = 0; i < b[u]; i++) rb.push_back(u);
  for (int i = ra.size(); i > 0; i--) printf("%d", ra[i - 1]);
  for (int i = 0; i < temp; i++) printf("0");
  printf("\n");
  for (int i = rb.size(); i > 0; i--) printf("%d", rb[i - 1]);
  for (int i = 0; i < temp; i++) printf("0");
}
