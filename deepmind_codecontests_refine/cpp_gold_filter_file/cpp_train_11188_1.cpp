#include <bits/stdc++.h>
using namespace std;
map<string, string> h;
vector<string> arr;
int main() {
  int q, i, sz;
  string str1, str2;
  ios::sync_with_stdio(false);
  cin >> q;
  for (i = 0; i < q; i++) {
    cin >> str1 >> str2;
    if (h[str1].size() == 0) {
      arr.push_back(str1);
      h[str1] = str2;
      h[str2] = str1;
    } else {
      h[h[str1]] = str2;
      h[str2] = h[str1];
    }
  }
  sz = arr.size();
  cout << sz << endl;
  for (i = 0; i < sz; i++) {
    cout << arr[i] << " " << h[arr[i]] << endl;
  }
  return 0;
}
