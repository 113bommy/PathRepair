#include <bits/stdc++.h>
using namespace std;
bool ask(int a, int b) {
  if (a == -1 || b == -1) return 0;
  cout << "1 " << a << " " << b << endl;
  string ans;
  cin >> ans;
  return (ans == "TAK");
}
int bin(int s, int f) {
  if (s > f) return -1;
  int l = s, r = f;
  while (l < r) {
    int m = (l + r) / 2;
    if (ask(m, m + 1))
      r = m;
    else
      l = m + 1;
  }
  return l;
}
int main() {
  int n, k;
  cin >> n >> k;
  int p1 = bin(1, n);
  int p2 = bin(1, p1 - 1);
  if (!ask(p2, p1)) p2 = bin(p1 + 1, n);
  cout << "2 " << p1 << " " << p2 << endl;
  return 0;
}
