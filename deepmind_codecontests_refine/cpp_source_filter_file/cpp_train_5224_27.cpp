#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int N;
  cin >> N;
  string input;
  cin >> input;
  int arr[10];
  for (int i = 0; i < 10; i++) arr[i] = 0;
  for (int i = 0; i < input.size(); i++) {
    char ch = input[i];
    if (ch == 'L') {
      for (int j = 0; j < 10; j++) {
        if (arr[j] == 0) {
          arr[j] = 1;
          break;
        }
      }
    } else if (ch == 'R') {
      for (int j = 9; j >= 0; j++) {
        if (arr[j] == 0) {
          arr[j] = 1;
          break;
        }
      }
    } else {
      int k = int(ch - '0');
      arr[k] = 0;
    }
  }
  string output = "";
  for (int i = 0; i < 10; i++) {
    output += arr[i] + '0';
  }
  cout << output << endl;
  return 0;
}
