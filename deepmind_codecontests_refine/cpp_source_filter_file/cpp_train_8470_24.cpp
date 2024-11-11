#include <bits/stdc++.h>
using namespace std;
bool Answer(int n) {
  int tmp = n, l;
  vector<int> dig;
  while (tmp != 0) {
    dig.push_back(tmp % 10);
    tmp /= 10;
  }
  l = dig.size();
  for (int i = 0; i < l - 1; i++) {
    for (int j = 0; j < l; j++) {
      if (i == j) continue;
      if (dig[i] == dig[j]) return false;
    }
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  bool tmp;
  n++;
  while (n != 9001) {
    tmp = Answer(n);
    if (tmp) {
      break;
    }
    n++;
  }
  cout << n << endl;
}
