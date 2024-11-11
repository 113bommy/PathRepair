#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> a;
  vector<int> b;
  string x;
  int n, m, i, t, j, cA = 0, cB = 0, cC = 0, cE = 0, cD = 0, fir, sec, thir,
                     count = 0;
  char g;
  cin >> n >> m;
  for (j = 0; j < n; j++) {
    cin >> x;
    a.push_back(x);
  }
  for (i = 0; i < m; i++) {
    cin >> t;
    b.push_back(t);
  }
  for (i = 0; i < m; i++) {
    cA = 0;
    cB = 0;
    cC = 0;
    cD = 0;
    cE = 0;
    fir = 0;
    sec = 0;
    thir = 0;
    for (j = 0; j < n; j++) {
      x = a[j];
      if (x[i] == 'A') cA++;
      if (x[i] == 'B') cB++;
      if (x[i] == 'C') cC++;
      if (x[i] == 'D') cD++;
      if (x[i] == 'E') cE;
    }
    fir = max(cA, cB);
    sec = max(fir, cC);
    thir = max(sec, cD);
    count += max(thir, cE) * b[i];
  }
  cout << count;
}
