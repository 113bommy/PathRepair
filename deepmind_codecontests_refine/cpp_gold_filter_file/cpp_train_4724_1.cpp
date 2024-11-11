#include <bits/stdc++.h>
using namespace std;
struct Node {
  int a, b;
  bool operator<(const Node &r) const { return a < r.a; }
};
Node a[1000005];
char s[1000005];
int main() {
  cin >> s;
  int ll = strlen(s);
  int l = 1, r = ll;
  for (int i = 0; i < ll; i++) {
    if (s[i] == 'l') {
      a[i].a = r;
      r--;
    } else {
      a[i].a = l;
      l++;
    }
    a[i].b = i + 1;
  }
  sort(a, a + ll);
  for (int i = 0; i < ll; i++) cout << a[i].b << "\n";
  return 0;
}
