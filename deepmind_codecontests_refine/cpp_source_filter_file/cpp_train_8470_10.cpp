#include <bits/stdc++.h>
using namespace std;
string str;
int arr[10];
int main() {
  int year;
  cin >> year;
  stringstream ss;
  for (int i = year + 1; i <= 9000; i++) {
    int f = 0;
    memset(arr, 0, sizeof(arr));
    str.clear();
    ss.str("");
    ss << i;
    str = ss.str();
    for (int j = 0; j < str.length(); j++) arr[str[j] - '0']++;
    for (int j = 0; j < 10; j++)
      if (arr[j] > 1) f = 1;
    if (f == 0) {
      year = i;
      break;
    }
  }
  cout << year;
  return 0;
}
