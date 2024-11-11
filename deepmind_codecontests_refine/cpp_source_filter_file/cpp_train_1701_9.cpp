#include <bits/stdc++.h>
using namespace std;
int main() {
  string name[1001], s;
  int n, i, j, mas[1001], p, top = -1;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s >> p;
    bool flag = true;
    for (j = 0; flag && j <= top; j++)
      if (name[j] == s) {
        flag = false;
        mas[j] = max(mas[j], p);
      }
    if (flag) {
      top++;
      mas[top] = p;
      name[top] = s;
    }
  }
  n = top;
  cout << n + 1 << endl;
  for (i = 0; i <= n; i++) {
    double count = 0, nn = n + 1;
    for (j = 0; j <= n; j++)
      if (mas[i] < mas[j]) count++;
    if (count > nn / 2)
      cout << name[i] << " noob" << endl;
    else if (count >= nn / 5)
      cout << name[i] << " random" << endl;
    else if (count >= nn / 10)
      cout << name[i] << " raverage" << endl;
    else if (count > nn / 100)
      cout << name[i] << " hardcore" << endl;
    else
      cout << name[i] << " pro" << endl;
  }
  return 0;
}
