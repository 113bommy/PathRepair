#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string temp;
  cin >> temp;
  int a = 0;
  int d = 0;
  for (int i = 0; i < temp.size(); i++) {
    if (temp[i] == 'A') {
      a++;
    }
    if (temp[i] == 'D') {
      d++;
    }
  }
  if (d == a) {
    cout << "Friendship" << endl;
    return 0;
  }
  if (a < d) {
    cout << "Danik" << endl;
    return 0;
  }
  if (a > d) {
    cout << "Anton" << endl;
    return 0;
  }
}
