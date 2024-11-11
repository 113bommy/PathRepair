#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> numbers{47, 74, 4477, 4747, 4774, 7447, 7474, 7744};
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 5; j++) {
      for (int k = j + 1; k < 6; k++) {
        string s = "";
        for (int l = 0; l < 6; l++) {
          if ((l == i) || (l == j) || (l == k)) {
            s = s + "4";
          } else {
            s = s + "7";
          }
        }
        numbers.push_back(stoi(s));
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 6; j++) {
      for (int k = j + 1; k < 7; k++) {
        for (int l = k + 1; l < 8; l++) {
          string s = "";
          for (int m = 0; m < 8; m++) {
            if ((m == i) || (m == j) || (m == k) || (m == l)) {
              s = s + "4";
            } else {
              s = s + "7";
            }
          }
          numbers.push_back(stoi(s));
        }
      }
    }
  }
  numbers.push_back(4444477777);
  int N;
  cin >> N;
  for (int i = 0; i < numbers.size(); i++) {
    if ((numbers[i] < N) && (N < numbers[i + 1])) {
      cout << numbers[i + 1];
      return 0;
    } else if (numbers[i] == N) {
      cout << N;
      return 0;
    } else if (N < 47) {
      cout << 47;
      return 0;
    }
  }
  return 0;
}
