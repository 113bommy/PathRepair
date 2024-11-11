#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j;
  string s1, s2;
  cin >> n;
  cin >> s1 >> s2;
  vector<int> v1, v2;
  for (i = 0; i < n; i++) {
    if (s2[i] == 'a' && s2[i] != s1[i])
      v1.push_back(i + 1);
    else if (s2[i] == 'b' && s2[i] != s1[i])
      v2.push_back(i + 1);
  }
  if ((v1.size() + v2.size()) % 2 != 0)
    cout << "-1";
  else {
    j = v1.size() + v2.size();
    if (v1.size() % 2 != 0) {
      j /= 2;
      j++;
      cout << j << endl;
      for (i = 1; i < v1.size(); i += 2) {
        cout << v1[i - 1] << " " << v1[i] << endl;
      }
      for (i = 1; i < v2.size(); i += 2) {
        cout << v2[i - 1] << " " << v2[i] << endl;
      }
      cout << v1[v1.size() - 1] << " " << v1[v1.size() - 1] << endl;
      cout << v2[v2.size() - 1] << " " << v1[v1.size() - 1];
    } else {
      j /= 2;
      cout << j << endl;
      for (i = 0; i < v1.size(); i += 2) {
        cout << v1[i] << " " << v1[i + 1] << endl;
      }
      for (i = 0; i < v2.size(); i += 2) {
        cout << v2[i] << " " << v2[i + 1] << endl;
      }
    }
  }
}
