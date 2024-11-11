#include <bits/stdc++.h>
using namespace std;
int A[200001];
bool R[200001];
string inp, target;
bool solve(int removes) {
  for (int i = 0; i < inp.size(); ++i) R[i] = false;
  for (int i = 0; i < removes; ++i) R[A[i] - 1] = true;
  int pos = 0;
  for (int i = 0; i < target.size(); ++i) {
    char c = target[i];
    while (true) {
      if (inp[pos] == c && !R[pos]) {
        pos++;
        break;
      }
      if (pos == inp.size()) return false;
      pos++;
    }
  }
  return true;
}
int main() {
  cin >> inp >> target;
  for (int i = 0; i < inp.size(); ++i) {
    cin >> A[i];
  }
  int l = 0;
  int r = inp.size() - 1;
  while (l < r) {
    int middle = (l + r) / 2;
    if (solve(middle)) {
      l = middle + 1;
    } else {
      r = middle;
    }
  }
  cout << r - 1 << endl;
  return 0;
}
