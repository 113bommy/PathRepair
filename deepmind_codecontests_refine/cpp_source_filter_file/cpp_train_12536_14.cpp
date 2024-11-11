#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    vector<int> num;
    int n0 = 0, n1 = 0;
    for (int i = 0; i < n; i++) {
      int number;
      cin >> number;
      num.push_back(number);
      if (number == 0) {
        n0++;
      } else {
        n1++;
      }
    }
    int answer = 0;
    int cnt0 = 0;
    for (int i = 0; i < n; i++) {
      if (num[i] == 0) {
        cnt0++;
      }
      if (num[i] == 1) {
        answer += n0 - cnt0;
        n1--;
      }
      if (n0 == cnt0) {
        break;
      }
    }
    cout << answer << endl;
  }
  return 0;
}
