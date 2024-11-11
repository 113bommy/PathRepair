#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, inp = 0, ret = 0, no25 = 0, no50 = 0, no100 = 0;
  cin >> n;
  while (n--) {
    cin >> inp;
    if (inp > 25) {
      ret = inp - 25;
      if (ret == 25) {
        if (no25 == 0) {
          cout << "NO" << endl;
          return 0;
        }
        no25--;
        no50++;
      } else if (ret == 75) {
        if (no50 >= 1 && no25 >= 2) {
          no50--;
          no25 = no25 - 2;
          no100++;
        } else if (no25 >= 3) {
          no25 = no25 - 3;
          no100++;
        } else {
          cout << "NO" << endl;
          return 0;
        }
      }
    } else {
      no25++;
    }
  }
  cout << "YES" << endl;
  return 0;
}
