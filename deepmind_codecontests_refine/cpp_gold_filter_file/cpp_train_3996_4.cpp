#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[100100];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  int curStair = 0;
  long long curH = a[0];
  for (int i = 0; i < m; i++) {
    long long w, h;
    cin >> w >> h;
    w--;
    if (w <= curStair) {
      cout << curH << endl;
      curH += h;
    } else {
      cout << a[w] << endl;
      curH = a[w] + h;
    }
    while (curStair + 1 < n && a[curStair + 1] <= curH) curStair++;
  }
}
