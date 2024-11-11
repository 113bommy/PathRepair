#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, active = 1;
  char inp;
  char arr[6] = {'C', 'M', 'Y', 'G'};
  cin >> n >> m;
  for (int j = 0; j < (n * m); j++) {
    cin >> inp;
    for (int i = 0; i < 6; i++) {
      if (arr[i] == inp) {
        cout << "#Color";
        return 0;
      }
    }
  }
  cout << "#Black&White";
}
