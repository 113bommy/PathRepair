#include <bits/stdc++.h>
using namespace std;
bool IsFail = false;
vector<int> answer;
vector<int> parent;
vector<int> r;
vector<vector<int>> smej;
vector<bool> usd;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int max = 0;
  int index = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0 && fabs(a[i]) > max) {
      max = fabs(a[i]);
      index = i;
    }
    if (a[i] >= 0 && a[i] + 1 >= max) {
      max = a[i] + 1;
      index = i;
    }
  }
  if (n == 1 && a[0] == 0)
    cout << 0;
  else {
    if (n % 2 == 0) {
      for (int i = 0; i < n; i++)
        if (a[i] >= 0)
          cout << a[i] * (-1) - 1 << " ";
        else
          cout << a[i] << " ";
    } else {
      for (int i = 0; i < n; i++)
        if (index == i && a[i] >= 0)
          cout << a[i] << " ";
        else if (index == i && a[i] < 0)
          cout << a[i] * (-1) - 1 << " ";
        else if (a[i] >= 0)
          cout << a[i] * (-1) - 1 << " ";
        else
          cout << a[i] << " ";
    }
  }
}
