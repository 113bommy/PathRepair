#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[4] = {2, 3, 5, 7};
  int prime_2[19] = {4,  8,  16, 32, 64, 3,  5,  7,  11, 13,
                     17, 19, 23, 29, 31, 37, 41, 43, 47};
  int prime_3[13] = {9, 27, 81, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  int prime_5[6] = {25, 7, 11, 13, 17, 19};
  int prime_7[3] = {49, 11, 13};
  bool flag = 0;
  vector<vector<int> > inp(4, vector<int>());
  for (int i = 0; i < 19; i++) {
    inp[0].push_back(prime_2[i]);
  }
  for (int i = 0; i < 12; i++) {
    inp[1].push_back(prime_3[i]);
  }
  for (int i = 0; i < 6; i++) {
    inp[2].push_back(prime_5[i]);
  }
  for (int i = 0; i < 3; i++) {
    inp[3].push_back(prime_7[i]);
  }
  string str = "2357", s;
  for (int i = 0; i < 4; i++) {
    cout << str[i] << endl;
    fflush(stdout);
    cin >> s;
    if (s == "yes") {
      for (int j = 0; j < inp[i].size(); j++) {
        cout << inp[i][j] << endl;
        fflush(stdout);
        cin >> s;
        if (s == "yes") {
          flag = 1;
          break;
        }
      }
      break;
    }
  }
  if (flag == 0) {
    cout << "prime" << endl;
    fflush(stdout);
  } else {
    cout << "composite" << endl;
    fflush(stdout);
  }
}
