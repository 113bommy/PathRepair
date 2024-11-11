#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  vector<int> pos;
  int count = 0;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] != s2[i]) {
      count++;
      pos.push_back(i);
    }
  }
  if (count % 2 != 0) {
    printf("impossible\n");
  } else {
    string s3 = s1;
    for (int i = 0; i < (pos.size() / 2); i++) {
      s3[pos[i]] = s2[pos[i]];
    }
    cout << s3 << "\n";
  }
  return 0;
}
