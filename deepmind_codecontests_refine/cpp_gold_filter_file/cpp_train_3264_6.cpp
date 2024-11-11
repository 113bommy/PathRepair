#include <bits/stdc++.h>
using namespace std;
vector<int> v, v1;
int main() {
  int n, m, n1, nn;
  scanf("%d%d", &n, &m);
  nn = n;
  int amin = 0, amax = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", &n1);
    v.push_back(n1);
    v1.push_back(n1);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size() && n > 0; i++) {
    if (n >= v[i]) {
      amin += (v[i] * (v[i] + 1) / 2);
      n -= v[i];
    } else {
      amin += ((v[i] * (v[i] + 1) / 2) - ((v[i] - n) * (v[i] - n + 1) / 2));
      n = 0;
    }
  }
  n = nn;
  int mm;
  for (int i = 0; i < n; i++) {
    mm = 0;
    for (int j = 1; j < m; j++)
      if (v1[mm] < v1[j]) mm = j;
    amax += v1[mm];
    v1[mm]--;
  }
  cout << amax << " " << amin << endl;
  return 0;
}
