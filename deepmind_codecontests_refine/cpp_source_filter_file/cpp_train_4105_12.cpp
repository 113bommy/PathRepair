#include <bits/stdc++.h>
using namespace std;
int n, temp;
int first = -1, sec = -1;
int ifirst = -1, isec = -1;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp > first) {
      sec = first;
      isec = ifirst;
      first = temp;
      ifirst = i + 1;
    } else if (temp > sec) {
      sec = temp;
      isec = i + 1;
    }
  }
  cout << isec << " " << sec << endl;
  return 0;
}
