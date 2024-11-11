#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
int main() {
  int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  for (int i = 0; i < 15; ++i) {
    cout << arr[i] << endl;
    cin >> s;
    if (s == "yes") ++cnt;
    if (i < 4 && s == "yes") {
      cout << arr[i] * arr[i] << endl;
      cin >> s;
      if (s == "yes") return cout << "composite" << endl, 0;
    }
    if (cnt > 1) return cout << "composite" << endl, 0;
  }
  cout << "prime" << endl;
  return 0;
}
