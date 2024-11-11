#include <bits/stdc++.h>
using namespace std;
int x[3005];
int y[3005];
bool visit[2005][2005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i] += 1000;
    y[i] += 1000;
    visit[x[i]][y[i]] = 1;
  }
  int res = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      if (((x[i] + x[j]) % 2 == 0) && ((y[i] + y[j]) % 2 == 0) &&
          (visit[(x[i] + x[j]) / 2][(y[i] + y[j]) / 2] == 1))
        res++;
    }
  cout << res << endl;
  return 0;
}
