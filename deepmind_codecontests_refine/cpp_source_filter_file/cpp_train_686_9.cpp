#include <bits/stdc++.h>
using namespace std;
int main() {
  int number1, number2;
  cin >> number1 >> number2;
  int list1[number1], list2[number2];
  for (int i = 0; i < number1; i++) {
    cin >> list1[i];
  }
  for (int j = 0; j < number2; j++) {
    cin >> list2[j];
  }
  int low = 10;
  for (int k = 0; k < number1; k++) {
    for (int l = 0; l < number2; l++) {
      if (list1[k] == list2[l]) {
        if (list1[k] < low) {
          low = list1[k];
        }
      }
    }
  }
  if (low < 10) {
    cout << low << endl;
    return 0;
  }
  int low1 = 10, low2 = 10;
  for (int m = 0; m < number1; m++) {
    if (list1[m] < low1) {
      low1 = list1[m];
    }
  }
  for (int n = 0; n < number1; n++) {
    if (list2[n] < low2) {
      low2 = list2[n];
    }
  }
  if (low1 >= low2) {
    cout << low2 << low1 << endl;
    return 0;
  } else {
    cout << low1 << low2 << endl;
    return 0;
  }
}
