#include <bits/stdc++.h>
using namespace std;
string A;
int i, j;
int main() {
  int countc[26] = {0};
  cin >> A;
  char maX = 'a';
  int idx = -1;
  for (i = 0; i < A.size(); i++) {
    if (A[i] > maX) {
      maX = A[i];
      idx = i;
    }
  }
  int start = idx;
  for (i = maX; i >= 'a'; i--) {
    start = idx;
    for (j = start; j < A.size(); j++) {
      if (i == A[j]) {
        countc[i - 'a']++;
        idx = j;
      }
    }
  }
  string res = "";
  for (i = maX; i >= 'a'; i--) {
    for (j = 0; j < countc[i - 'a']; j++) res += i;
  }
  cout << res << endl;
  return 0;
}
