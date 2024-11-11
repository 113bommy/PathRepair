#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string binary, answer;
    cin >> binary;
    int k = 1;
    int maxLen = binary.size() * 2;
    for (int i = 0; i < binary.size() - k; i += k) {
      if (binary[i] == binary[i + k]) {
        continue;
      }
      if (binary[i] != binary[i + 1]) {
        k++;
        i = 0;
        answer.clear();
      }
    }
    char firstChar = binary[0];
    for (int i = 0; i < binary.size(); i++) {
      if (firstChar == '0') {
        if (i % 2 == 1 && k > 1)
          answer += '1';
        else
          answer += '0';
      } else {
        if (i % 2 == 1 && k > 1)
          answer += '0';
        else
          answer += '1';
      }
    }
    cout << answer << endl;
  }
}
