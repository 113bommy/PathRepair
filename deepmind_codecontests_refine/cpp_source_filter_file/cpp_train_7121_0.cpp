#include <bits/stdc++.h>
using namespace std;
int n[2];
int k;
int a;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> a;
    if (a == 0)
      n[0]++;
    else
      n[1]++;
  }
  if (n[0] == 0) {
    cout << "-1" << endl;
    return 0;
  } else if (n[1] == 0) {
    cout << "0" << endl;
    return 0;
  } else {
    while (n[1] >= 9) {
      cout << "555555555";
      n[1] -= 9;
    }
    while (n[0] >= 1) {
      cout << "0";
      n[0]--;
    }
    cout << endl;
    return 0;
  }
  return 0;
}
