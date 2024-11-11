#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, id;
} s[100101];
bool cmp(node a, node b) { return a.x < b.x; }
int main() {
  int n, i, j, x;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s[i].x;
    s[i].id = i + 1;
  }
  sort(s, s + n, cmp);
  if (n / 2)
    x = n / 2 + 1;
  else
    x = n / 2;
  cout << x << endl;
  for (i = 0; i < n; i += 2) cout << s[i].id << " ";
  cout << endl << n - x << endl;
  for (i = 1; i < n; i += 2) cout << s[i].id << " ";
  cout << endl;
}
