#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int array[n];
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
  int temp, son = 0;
  temp = 7;
  for (int i = 0; i < n; i++) {
    while (array[i] >= 0 && temp >= 2) {
      if (array[i] - temp >= 0) {
        son++;
        array[i] = array[i] - temp;
      } else {
        temp--;
      }
    }
    cout << son << endl;
    son = 0;
    temp = 7;
  }
  return 0;
}
