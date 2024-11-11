#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  cin >> num;
  int count = 0;
  if (num >= 5) {
    count += num / 5;
    num %= 5;
  }
  if (num >= 4) {
    count += num / 4;
    num %= 4;
  }
  if (num >= 3) {
    count += num / 3;
    num %= 3;
  }
  if (num >= 2) {
    count += num / 2;
    num %= 2;
  }
  if (num >= 1) {
    count += num;
  }
  cout << count << endl;
  return 0;
}
