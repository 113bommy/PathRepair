#include <bits/stdc++.h>
using namespace std;
int arry[5050];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arry[i]);
  if (n == 2) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (arry[arry[arry[i]]] == i) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
