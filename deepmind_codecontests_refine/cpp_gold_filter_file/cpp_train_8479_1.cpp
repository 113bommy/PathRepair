#include <bits/stdc++.h>
using namespace std;
bool visi[100001];
int main() {
  int n, k;
  cin >> n >> k;
  int a = 1, b = n;
  bool change = false;
  for (int i = 0; i < k; i++)
    if (!change) {
      change = true;
      visi[a] = true;
      cout << a << " ";
      a++;
    } else {
      change = false;
      visi[b] = true;
      cout << b << " ";
      b--;
    }
  if (k % 2 == 0) {
    for (int i = n; i > 0; i--)
      if (!visi[i]) cout << i << " ";
  } else
    for (int i = 1; i <= n; i++)
      if (!visi[i]) cout << i << " ";
  cout << endl;
  return 0;
}
