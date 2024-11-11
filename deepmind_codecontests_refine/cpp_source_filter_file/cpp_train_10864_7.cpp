#include <bits/stdc++.h>
using namespace std;
bool prob[10010];
int main() {
  int n;
  int mas[10010][2];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> mas[i][0] >> mas[i][1];
    if (mas[i][0] > mas[i][1]) swap(mas[i][0], mas[i][1]);
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i; j < n; j++) {
      if (mas[i][1] > mas[j][1]) swap(mas[i], mas[j]);
    }
  }
  int count = 0, gv[1001] = {};
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j < n; j++)
      if (mas[j][1] == i && !prob[j]) {
        gv[count] = i;
        prob[j] = true;
        count++;
        for (int q = 0; q < n; q++)
          if (mas[q][0] <= i && mas[q][1] >= i) prob[q] = true;
      }
  }
  cout << count << endl;
  for (int i = 0; i < count; i++) {
    cout << gv[i] << " ";
  }
}
