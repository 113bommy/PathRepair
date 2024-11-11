#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101;
int n, pep[MAXN], mtime = 50016, ttime = 0, a;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> pep[i];
  for (int i = 0; i < n; i++) {
    ttime = 0;
    for (int j = 0; j < pep[i]; j++) {
      cin >> a;
      ttime += a * 5;
      ttime += 15;
    }
    mtime = min(mtime, ttime);
  }
  cout << mtime;
}
