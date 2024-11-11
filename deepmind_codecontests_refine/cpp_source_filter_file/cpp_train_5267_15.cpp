#include <bits/stdc++.h>
using namespace std;
void printStr(int i) {
  int t = i % 26;
  char c = t + 'A';
  cout << c;
  t /= 26;
  if (t) {
    c = t + 'a';
    cout << c;
  }
  cout << " ";
}
int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < k - 1; i++) arr[i] = i;
  for (int i = k - 1; i < n; i++) {
    string str;
    cin >> str;
    if (str[0] == 'Y') {
      arr[i] = i;
    } else {
      arr[i] = arr[i - k + 1];
    }
  }
  for (int i = 0; i < n; i++) {
    printStr(arr[i]);
  }
  cout << endl;
  return 0;
}
