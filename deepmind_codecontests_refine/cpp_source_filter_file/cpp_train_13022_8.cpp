#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int ar[m];
  for (int i = 1; i <= m; i++) ar[i] = 0;
  while (n--) {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) ar[i] = 1;
  }
  int flag = 0;
  int count = 0;
  for (int i = 1; i <= m; i++) {
    if (ar[i] == 0) {
      count++;
      ar[i] = 2;
      flag = 1;
    }
  }
  cout << count << endl;
  for (int i = 1; i < m; i++) {
    if (ar[i] == 2) cout << i << " ";
  }
  cout << endl;
}
