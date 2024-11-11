#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a1 = 0, a2 = 0, a3 = 0;
  cin >> n >> m;
  vector<int> vec(n);
  int tem1, tem2;
  for (int i = 0; i < m; i++) {
    cin >> tem1 >> tem2;
    vec[tem1 - 1]++;
    vec[tem2 - 1]++;
  }
  for (int i = 0; i < n; i++) {
    if (vec[i] == 1)
      a1++;
    else if (vec[i] == 2)
      a2++;
    else
      a3++;
  }
  if (a2 == n)
    cout << "ring topology";
  else if (a1 == 2 && a2 == n - 2)
    cout << "bus topology";
  else if (a1 == n - 1 && a3 == 1)
    cout << "star topology";
  else
    cout << "unknown topology";
}
