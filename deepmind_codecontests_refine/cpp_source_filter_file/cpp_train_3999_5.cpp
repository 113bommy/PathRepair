#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string curr;
  string prev;
  int gc = 0;
  while (n--) {
    cin >> curr;
    if (curr == prev && curr != "")
      continue;
    else
      gc++;
    prev = curr;
  }
  cout << gc - 1;
  return 0;
}
