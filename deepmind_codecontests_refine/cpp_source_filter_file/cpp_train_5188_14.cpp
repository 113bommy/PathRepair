#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string x;
  cin >> n;
  while (n>0) {
    cin >> x;
    if (x="Y") {
      cout << "Four";
      break;
    }
    n--;
  }
  if (n=0) cout << "Three";
}