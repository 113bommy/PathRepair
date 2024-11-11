#include <bits/stdc++.h>
using namespace std;
int main() {
  string str1;
  string str2[10];
  cin >> str1;
  for (int i = 0; i < 10; i++) {
    cin >> str2[i];
  }
  for (int i = 0; i < 80; i += 10) {
    for (int j = 0; j < 10; j++) {
      if (str1.substr(i, i + 10) == str2[j]) {
        cout << j;
      }
    }
  }
}
