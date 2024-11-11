#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  vector<string> mas(n);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    mas[i] = s;
  }
  if (n == 1) {
    cout << 6;
    return 0;
  }
  int min = INT_MAX;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j) {
        int tmp = 0;
        for (int k = 0; k < 6; k++)
          if (mas[i][k] != mas[j][k]) tmp++;
        if (tmp < min) min = tmp;
      }
  cout << (min - 1) / 2;
}
