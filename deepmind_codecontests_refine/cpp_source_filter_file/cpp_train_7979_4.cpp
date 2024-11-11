#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, temp, num[100000];
  bool all = true;
  bool check[100000];
  memset(check, 0, sizeof(check));
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    num[i] = -1;
  }
  for (int i = 0; i < m; ++i) {
    cin >> temp;
    temp--;
    check[temp] = true;
    if (num[temp] == -1) {
      num[temp] = 1;
    } else
      num[temp]++;
  }
  sort(num, num + m);
  for (int i = 0; i < m; ++i) {
    if (check[i] == false) {
      all = false;
      break;
    }
  }
  if (all == false) {
    cout << '0' << endl;
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    if (num[i] > -1) {
      cout << num[i] << endl;
      break;
    }
  }
  return 0;
}
