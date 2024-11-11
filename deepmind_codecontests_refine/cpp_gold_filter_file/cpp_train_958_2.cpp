#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  char m[11], arr[10] = {'0'};
  int digit = 0;
  cin >> n >> m;
  while (n != 0) {
    arr[digit++] = '0' + n % 10;
    n = n / 10;
  }
  sort(arr, arr + digit);
  if (arr[0] == '0') {
    for (int i = 1; i < digit; ++i) {
      if (arr[i] != '0') {
        arr[0] = arr[i];
        arr[i] = '0';
        break;
      }
    }
  }
  if (strcmp(m, arr) == 0) {
    cout << "OK" << endl;
  } else {
    cout << "WRONG_ANSWER" << endl;
  }
  return 0;
}
