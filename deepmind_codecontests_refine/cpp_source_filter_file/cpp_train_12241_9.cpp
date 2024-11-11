#include <bits/stdc++.h>
using namespace std;
char rez[1000][1000];
int main() {
  int n;
  cin >> n;
  string s1;
  cin >> s1;
  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++) rez[i][j] = ' ';
  int mv = 1;
  int s = 0;
  for (int t = 0; t < n; t++)
    if (s1[t] == '[') {
      s++;
      if (s > mv) mv = s;
    } else
      s--;
  int h = mv * 2 + 1;
  int ser = h / 2;
  int h1 = h;
  int u = 0;
  for (int i = 0; i < n; i++)
    if (s1[i] == '[') {
      rez[u][ser - h1 / 2] = rez[u][ser + h1 / 2] = '+';
      for (int j = ser - h1 / 2 + 1; j < ser + h1 / 2; j++) rez[u][j] = '|';
      u++;
      rez[u][ser - h1 / 2] = rez[u][ser + h1 / 2] = '-';
      h1 -= 2;
    } else {
      if (s1[i - 1] == '[') u += 2;
      h1 += 2;
      rez[u][ser - h1 / 2] = rez[u][ser + h1 / 2] = '-';
      u++;
      rez[u][ser - h1 / 2] = rez[u][ser + h1 / 2] = '+';
      for (int j = ser - h1 / 2 + 1; j < ser + h1 / 2; j++) rez[u][j] = '|';
      if (i < n - 1 && s1[i + 1] == '[') u++;
    }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < u; j++) cout << rez[j][i];
    cout << endl;
  }
  return 0;
}
