#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int input = 0;
    cin >> input;
    mp[input]++;
  }
  map<int, int>::iterator it;
  int flag = 0;
  if (n % 2 == 0) flag = 1;
  if (flag == 1) {
    bool temp = 0;
    for (it = mp.begin(); it != mp.end(); it++) {
      if (it->second >= ((n / 2) + 1)) {
        cout << "NO";
        temp = 1;
        break;
      }
    }
    if (temp == 0) cout << "YES";
  } else {
    bool temp = 0;
    for (it = mp.begin(); it != mp.end(); it++) {
      if (it->second >= ((n / 2) + 2)) {
        cout << "NO";
        temp = 1;
        break;
      }
    }
    if (temp == 0) cout << "YES";
  }
}
