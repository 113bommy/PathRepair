#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  int max = 0, ind = -1;
  for (int i = 0; i < n; i++) {
    if (v[i] > max) {
      max = v[i];
      ind = i;
    }
  }
  int flag = 0;
  for (int i = 0; i < ind; i++) {
    if (v[i] >= v[i + 1]) {
      flag++;
      break;
    }
  }
  if (flag == 1) {
    cout << "NO" << endl;
  } else {
    for (int i = ind + 1; i < n - 1; i++) {
      if (v[i] <= v[i + 1]) {
        flag++;
        break;
      }
    }
    if (flag == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
