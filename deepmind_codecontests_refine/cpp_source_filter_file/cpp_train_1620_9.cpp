#include <bits/stdc++.h>
using namespace std;
int solve_equation(long long x) {
  long long a = (1 + (sqrt(1 - (4 * -2 * x)))) / 2;
  if ((a * a) - a != 2 * x) return -1 << 30;
  return a;
}
int main() {
  int in[4];
  for (int i = 0; i < 4; i++) cin >> in[i];
  if (solve_equation(in[0]) == -1 << 30 || solve_equation(in[3]) == -1 << 30) {
    cout << "Impossible";
    return 0;
  }
  if (!in[0] && !in[1] && !in[2] && !in[3]) {
    cout << "1";
    return 0;
  }
  if ((in[1] || in[2]) && in[0] + in[3] == 0) {
    cout << "Impossible";
    return 0;
  }
  int x[4];
  x[0] = solve_equation(in[0]);
  x[3] = solve_equation(in[3]);
  if (in[0] + in[1] + in[2] == 0 && x[3]) {
    for (int i = 0; i < x[3]; i++) cout << 1;
    return 0;
  }
  if (in[3] + in[2] + in[1] == 0 && x[0]) {
    for (int i = 0; i < x[0]; i++) cout << 0;
    return 0;
  }
  string str = "";
  for (int i = 0; i < x[0]; i++) str += '0';
  if (x[0]) {
    int temp = in[1] / x[0];
    int rem = in[1] % x[0];
    for (int i = 0; i < temp; i++) str += '1', x[3]--;
    for (int i = 0, j = 0; rem && i < str.size(); i++) {
      if (str[i] == '0') j++;
      if (j == rem) {
        str.insert(i + 1, 1, '1');
        x[3]--;
        if (in[2] - (x[0] - rem) < 0) {
          cout << "Impossible";
          return 0;
        }
        in[2] -= (x[0] - rem);
        break;
      }
    }
  }
  if (x[0] && in[2] % x[0] != 0) {
    cout << "Impossible";
    return 0;
  }
  string temp_buff = "";
  for (int i = 0; i < in[2] / x[0]; i++) {
    temp_buff += '1';
    x[3]--;
  }
  if (x[3] != 0 || str.size() > 1000000) {
    cout << "Impossible";
    return 0;
  }
  cout << temp_buff + str;
  return 0;
}
