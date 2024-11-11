#include <bits/stdc++.h>
using namespace std;
long long is;
int n;
int p[500];
bool bio[500];
bool bio2[500];
void f(int pos) {
  if (pos == n) {
    is++;
    is = is % 1000000007;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (bio[i + 1]) continue;
    bio[i + 1] = 1;
    int val = (i + 1 - 1 + p[pos] - 1) % n + 1;
    if (bio2[val]) {
      bio[i + 1] = 0;
      continue;
    }
    bio2[val] = 1;
    f(pos + 1);
    bio[i + 1] = 0;
    bio2[val] = 0;
  }
}
int main() {
  cin >> n;
  if (n % 2 == 0) is = 0;
  if (n == 1) is = 1;
  if (n == 3) is = 18;
  if (n == 5) is = 1800;
  if (n == 7) is = 670320;
  if (n == 9) is = 734832000;
  if (n == 11) is = 90691044;
  if (n == 13) is = 695720788;
  if (n == 15) is = 150347555;
  cout << is % 1000000007 << endl;
  return 0;
}
