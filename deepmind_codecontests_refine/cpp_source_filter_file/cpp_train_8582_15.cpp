#include <bits/stdc++.h>
using namespace std;
int main() {
  int number, counter[6] = {0, 0, 0, 0, 0, 0};
  string str;
  string str_names[8] = {"vaporeon", "jolteon", "flareon", "espeon",
                         "umbreon",  "leafeon", "glaceon", "sylveon"};
  cin >> number >> str;
  if (number == 8) {
    cout << str_names[0];
  } else if (number == 7) {
    for (int i = 0; i < 7; i++) {
      if (str[i] == str_names[1][i]) {
        counter[0]++;
      }
      if (str[i] == str_names[2][i]) {
        counter[1]++;
      }
      if (str[i] == str_names[4][i]) {
        counter[2]++;
      }
      if (str[i] == str_names[5][i]) {
        counter[3]++;
      }
      if (str[i] == str_names[6][i]) {
        counter[4]++;
      }
      if (str[i] == str_names[7][i]) {
        counter[5]++;
      }
    }
    int max1 = 0;
    for (int i = 0; i < 6; i++) {
      max1 = max(max1, counter[i]);
    }
    for (int i = 0; i < 6; i++) {
      if (counter[i] == max1 && i < 3) {
        cout << str_names[i + 1];
      } else if (counter[i] == max1 && i >= 3) {
        cout << str_names[i + 2];
      }
    }
  } else {
    cout << str_names[3];
  }
  return 0;
}
