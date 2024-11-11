#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int p[N], ji[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  int a = -1, inf = 10000000;
  for (int i = 0; i < n; i++) {
    if (p[i] > a && (p[i] < p[i + 1] || p[i] > inf)) {
      a = p[i];
      ji[i] = 0;
    } else if (p[i] < inf) {
      inf = p[i];
      ji[i] = 1;
    } else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << ji[i] << (i == n - 1 ? " \n" : " ");
  }
}
