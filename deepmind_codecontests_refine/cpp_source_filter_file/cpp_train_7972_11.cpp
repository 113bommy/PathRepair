#include <bits/stdc++.h>
using namespace std;
struct data {
  int a;
  int b;
  int p;
} s[100001];
int n;
bool cmp(data x, data y) { return x.a < y.a; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].a;
    s[i].p = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i].b;
  }
  sort(s + 1, s + 1 + n, cmp);
  cout << n / 2 + 1 << endl;
  cout << s[1].p << " ";
  for (int i = 2; i <= n; i += 2) {
    if (s[i].b > s[i + 1].b)
      cout << s[i].p << " ";
    else
      cout << s[i + 1].p << " ";
  }
}
