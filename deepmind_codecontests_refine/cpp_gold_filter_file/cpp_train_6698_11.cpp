#include <bits/stdc++.h>
using namespace std;
int a, b[100001], c[100001];
int main() {
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    c[a] = i + 1;
  }
  for (i = 0; i < n; i++) cin >> b[i];
  for (i = 0; i < n; i++)
    if (i)
      cout << " " << c[b[i]];
    else
      cout << c[b[i]];
  cout << endl;
  return 0;
}
