#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, c, s, d, i, j;
  cin >> a >> c;
  long long a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  if (a == 5) {
    if (c > 5) {
      long long sum = 15;
      sum = sum - a1 - a2 - a3 - a4;
      cout << a1 << " " << a3 << " " << sum << " " << a4 << " " << a2 << endl;
      cout << a3 << " " << a1 << " " << sum << " " << a2 << " " << a4 << endl;
    } else {
      cout << -1;
      return 0;
    }
  }
  if (a > 5) {
    if (c < a + 1) {
      cout << -1;
      return 0;
    }
    vector<long long> vec(2000, 0);
    vec[0] = a1;
    vec[2] = a3;
    vec[a - 2] = a4;
    vec[a - 1] = a2;
    long long col = 0;
    vector<long long> ch;
    for (i = 1; i <= a; i++)
      if ((i != a1) && (i != a2) && (i != a3) && (i != a4)) ch.push_back(i);
    for (i = 0; i < a; i++) {
      if (vec[i] == 0) {
        vec[i] = ch[col];
        col++;
      }
    }
    cout << endl;
    for (i = 0; i < a; i++) cout << vec[i] << " ";
    cout << endl;
    for (i = 2; i < a - 2; i++) cout << vec[i] << " ";
    cout << vec[0] << " ";
    cout << vec[1] << " ";
    cout << vec[a - 1] << " ";
    cout << vec[a - 2] << " ";
  }
  if (a < 5) {
    cout << -1;
    return 0;
  }
}
