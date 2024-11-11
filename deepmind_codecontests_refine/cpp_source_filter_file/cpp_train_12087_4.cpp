#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, count[2];
  cin >> n;
  while (n--) {
    cin >> s;
    count[s] += 1;
  }
  if (count[1] >= 1) {
    cout << "HARD";
  } else {
    cout << "EASY";
  }
}
