#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int prime[] = {2,  3,  4,  5,  7,  9,  11, 13, 17, 19,
                 23, 25, 29, 31, 37, 41, 43, 47, 49};
  int count = 0;
  for (int i = 0; i <= 14; i++) {
    cout << prime[i] << endl;
    fflush(stdout);
    string inp;
    cin >> inp;
    if (inp == "yes") {
      count++;
    }
  }
  if (count > 1) {
    cout << "composite";
  } else {
    cout << "prime";
  }
  return 0;
}
