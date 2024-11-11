#include <bits/stdc++.h>
using namespace std;
vector<int> val = {4, 8, 15, 16, 23, 42};
int a[100100];
vector<int> b[10100];
int dd[1010];
int x[100100];
void check(int i) {
  if (i == 6) {
    for (int i = 1; i <= 4; ++i)
      if (x[i] * x[i + 1] != a[i]) return;
    cout << "! ";
    for (int i = 1; i <= 5; ++i) cout << x[i] << " ";
    for (auto i : val)
      if (!dd[i]) cout << i << " ";
    cout << endl;
    exit(0);
  }
  for (auto j : val)
    if (!dd[j]) {
      dd[j] = 1;
      x[i] = j;
      check(i + 1);
      dd[j] = 0;
    }
}
int main() {
  for (int i = 1; i <= 4; ++i) {
    cout << "? " << i << " " << i + 1 << endl;
    cin >> a[i];
  }
  check(1);
}
