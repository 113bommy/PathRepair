#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char arr[n];
  int sf, fs;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int j = 0; j < n - 1; j++) {
    if (arr[j] == 'S') {
      if (arr[j + 1] == 'F') sf++;
    } else if (arr[j] == 'F') {
      if (arr[j + 1] == 'S') fs++;
    }
  }
  if (sf > fs)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
