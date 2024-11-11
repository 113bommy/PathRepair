#include <bits/stdc++.h>
using namespace std;
string arr[1001];
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  bool check = false;
  for (int i = 0; i < n; i += 1) {
    string temp;
    cin >> temp;
    if (check) {
      arr[i] = temp;
      continue;
    }
    if (temp[0] == 'O' && temp[1] == 'O') {
      check = true;
      temp[0] = '+';
      temp[1] = '+';
    } else if (temp[3] == 'O' && temp[4] == 'O') {
      check = true;
      temp[3] = '+';
      temp[4] = '+';
    }
    arr[i] = temp;
  }
  if (check)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  for (int i = 0; i < n; i += 1) {
    cout << arr[i] << endl;
  }
  return 0;
}
