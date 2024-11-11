#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0;
  string s, t;
  cin >> n;
  cin >> s >> t;
  vector<int> vect;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i])
      continue;
    else {
      int flag = -1;
      for (int j = i + 1; j < n; j++) {
        if (s[j] == t[i]) {
          flag = j;
          break;
        }
      }
      if (flag == -1) {
        cout << "-1";
        return 0;
      }
      for (int j = flag - 1; j >= i; j--) {
        swap(s[j], s[j + 1]);
        vect.push_back(j);
        k++;
      }
    }
  }
  cout << k << endl;
  for (int i = 0; i < k; i++) cout << vect[i] << " ";
  return 0;
}
