#include <bits/stdc++.h>
using namespace std;
int arr[100010];
int main() {
  string str;
  cin >> str;
  int i, j, k, l;
  j = 0;
  for (i = 0; i < str.length(); i++) {
    if (str[i] == 'F') {
      if (i - j == 0)
        arr[i] = 0;
      else if (i - j > arr[i - 1])
        arr[i] = i - j;
      else {
        if (str[i - 1] == 'F')
          arr[i] = arr[i - 1] + 1;
        else
          arr[i] = arr[i - 1];
      }
      j++;
    } else {
      if (i > 0) arr[i] = arr[i - 1];
    }
  }
  cout << arr[str.length() - 1] << endl;
  return 0;
}
