#include <bits/stdc++.h>
using namespace std;
char b[205];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  string a;
  cin.get();
  getline(cin, a);
  cin >> b;
  int flag;
  int time;
  int place;
  int count = 0;
  if (a == "to head") {
    if (m > k) {
      flag = n - m + m + k - 2;
      place = -k;
    } else if (m < k) {
      flag = k - m;
      place = k;
    } else
      flag = 0;
  }
  if (a == "to tail") {
    if (m > k) {
      flag = n - k;
      place = k;
    } else if (m < k) {
      flag = n + k - 2;
      place = -k;
    } else
      flag = 0;
  }
  for (int i = 0; i < strlen(b); i++) {
    if (i < strlen(b) - 1) {
      flag--;
      if (b[i] == '1') {
        place++;
        if (place > -1 && place < 2) place = 2;
        if (place > n) place = 1 - n;
        if (place > 0) flag = 2 * n - 1 - place;
        if (place < 0) flag = n - 2 - place;
      }
    }
    if (flag == 0) {
      count++;
      time = i;
      break;
    }
    if (b[i] == '0') {
      place++;
      if (place > -1 && place < 2) place = 2;
      if (place > n) place = 1 - n;
    }
  }
  if (count == 0) cout << "Stowaway" << endl;
  if (count > 0)
    cout << "Controller"
         << " " << time + 1 << endl;
  return 0;
}
