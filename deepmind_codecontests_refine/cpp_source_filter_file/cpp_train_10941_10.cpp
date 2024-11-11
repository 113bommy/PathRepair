#include <bits/stdc++.h>
using namespace std;
int min1(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}
int main() {
  int v[10];
  int j_cost;
  string c;
  int s[3];
  s[0] = 0, s[1] = 0, s[2] = 0;
  for (int i = 0; i < 10; i++) v[i] = 100001;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> j_cost >> c;
    int sum = 0;
    for (int j = 0; j < c.size(); j++) {
      s[(int)c[j] - 65] = 1;
      sum = sum + ((int)c[j] - 63);
    }
    v[sum] = min1(v[sum], j_cost);
  }
  int sum;
  if (s[0] == 1 && s[1] == 1 && s[2] == 1) {
    sum = min1(v[5] + v[7], min1(v[6] + v[7], v[5] + v[6]));
    cout << min1(v[2] + v[3] + v[4],
                 min1(v[2] + v[7],
                      min1(v[3] + v[6], min1(v[4] + v[5], min1(v[9], sum)))))
         << endl;
  } else
    cout << "-1" << endl;
}
