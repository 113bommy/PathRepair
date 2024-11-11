#include <bits/stdc++.h>
using namespace std;
int main() {
  int length;
  cin >> length;
  int arr[length];
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }
  int pos1 = 0, pos2 = length - 1;
  while (arr[pos1] < arr[pos1 + 1]) {
    pos1++;
  }
  while (arr[pos2] < arr[pos2 - 1]) {
    pos2--;
  }
  for (int i = pos1; i < pos2 - 1; i++) {
    if (arr[i] != arr[i + 1]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
