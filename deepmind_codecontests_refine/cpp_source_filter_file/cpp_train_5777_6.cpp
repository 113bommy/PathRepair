#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  cin >> num;
  int count;
  if (num == 2) {
    cout << 1 << endl;
    cout << 1;
    return 0;
  }
  if (num == 1) {
    cout << 1 << endl;
    cout << 1;
    return 0;
  }
  if (num == 3) {
    cout << 2 << endl;
    cout << 1 << " " << 3;
    return 0;
  }
  if (num == 4) {
    cout << 4 << endl;
    cout << 3 << " " << 1 << " " << 4 << " " << 2;
    return 0;
  }
  cout << num << endl;
  for (int i = 1; i < num; i = i + 2) {
    cout << i << " ";
  }
  for (int i = 2; i <= num; i = i + 2) {
    cout << i << " ";
  }
}
