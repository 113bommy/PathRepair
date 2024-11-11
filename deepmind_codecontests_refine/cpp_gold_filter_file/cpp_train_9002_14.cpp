#include <bits/stdc++.h>
using namespace std;
void yala_bena() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
}
const int m_r = 199999;
double pii = 3.1415926536;
int main() {
  yala_bena();
  long long graph[110][110] = {}, n, x, y, x1, y1, sum = 0;
  cin >> n;
  while (n--) {
    cin >> x >> y >> x1 >> y1;
    for (int i = x; i <= x1; i++)
      for (int j = y; j <= y1; j++) graph[i][j]++;
  }
  for (int i = 0; i <= 109; i++)
    for (int j = 0; j <= 109; j++) sum += graph[i][j];
  cout << sum << endl;
}
