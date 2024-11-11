#include <bits/stdc++.h>
using namespace std;
long long arr[100005], arrP[10005];
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s.substr(i, 3) == "144")
      i += 2;
    else if (s.substr(i, 2) == "14")
      i++;
    else if (s.substr(i, 1) == "1") {
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
