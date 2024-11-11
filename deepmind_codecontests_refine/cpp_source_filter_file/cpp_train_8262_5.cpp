#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  int n = 0, count = 0, temp_count = 1;
  cin >> n;
  int arr[n];
  getline(cin, a);
  getline(cin, a);
  for (int i = 0; i < (n - 1); i++) {
    unsigned found = a.find(" ");
    b = a.substr(0, found);
    stringstream convert(b);
    if (convert >> arr[i])
      ;
    a.erase(0, found + 1);
  }
  stringstream convert1(a);
  if (convert1 >> arr[n - 1])
    ;
  for (int i = 0; i < n; i++) {
    temp_count = 1;
    for (int j = i + 1; j < n; j++) {
      if ((arr[i] == arr[j]) && (arr[i] != 0)) temp_count++;
    }
    if (temp_count > 2) {
      cout << "0";
      return 0;
    } else if (temp_count == 2)
      count++;
  }
  cout << count;
  return 0;
}
