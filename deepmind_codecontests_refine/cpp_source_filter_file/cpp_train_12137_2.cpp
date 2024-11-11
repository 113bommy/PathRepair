#include <bits/stdc++.h>
using namespace std;
struct Student {
  int calls;
  bool isAware = false;
  int number;
};
int main() {
  int n;
  int k = 0;
  int o[101][2] = {0};
  Student a[101];
  Student b;
  cin >> n;
  cin >> a[0].calls;
  a[0].number = 1;
  a[0].isAware = true;
  for (int i = 1; i < n; i++) {
    cin >> a[i].calls;
    a[i].number = i + 1;
    for (int j = i; j > 1; j--)
      if (a[j].calls > a[j - 1].calls) {
        b = a[j];
        a[j] = a[j - 1];
        a[j - 1] = b;
      }
  }
  for (int i = 0, j = n - 1; i < n; i++)
    if (a[i].calls > 0 && !a[i + 1].isAware) {
      o[k][0] = a[i].number;
      o[k++][1] = a[i + 1].number;
      a[i + 1].isAware = true;
      a[i].calls--;
      while (a[i].calls > 0 && !a[j].isAware) {
        o[k][0] = a[i].number;
        o[k++][1] = a[j].number;
        a[i].calls--;
        a[j--].isAware = true;
      }
    } else
      break;
  for (int i = 0; i < n; i++)
    if (!a[i].isAware) {
      cout << "-1";
      return 0;
    }
  cout << k << endl;
  for (int i = 0; i < k; i++) cout << o[i][0] << " " << o[i][1] << endl;
  return 0;
}
