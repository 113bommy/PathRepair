#include <bits/stdc++.h>
int cal(int x) {
  int sum = 0;
  for (int i = 1; i < x; i++) {
    sum = sum + i;
  }
  return sum;
};
char x[101][101];
using namespace std;
int main() {
  int n, c1 = 0, c2 = 0, total1 = 0, total2 = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> x[i][j];
      if (x[i][j] == 'c') c1++;
    }
    total1 = total1 + cal(c1);
    c1 = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (x[j][i] == 'c') c2++;
    }
    total2 = total2 + cal(c2);
    c2 = 0;
  }
  cout << total1 + total2;
  return 0;
}
