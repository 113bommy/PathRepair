#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, n;
  scanf("%d", &T);
  string s;
  char c;
  while (T--) {
    cin >> s;
    n = s.size();
    int a[26] = {0};
    vector<int> v, u;
    for (int i = 0; i < n; i++) a[(s[i] - 'a')]++;
    for (int i = 0; i < 26; i++) {
      if (a[i]) v.push_back(i);
    }
    if (v.size() == 1) {
      cout << s << endl;
      continue;
    } else if (v.size() == 2) {
      if (v[0] = v[1] - 1) {
        printf("No answer\n");
      } else {
        cout << s << endl;
      }
      continue;
    } else if (v.size() == 3) {
      if ((v[0] == v[1] - 1) && (v[1] == v[2] - 1)) {
        printf("No answer\n");
        continue;
      } else {
        if (v[0] == v[1] - 1) {
          u.push_back(v[0]);
          u.push_back(v[2]);
          u.push_back(v[1]);
        } else {
          u.push_back(v[1]);
          u.push_back(v[0]);
          u.push_back(v[2]);
        }
      }
    } else if (v.size() == 4) {
      u.push_back(v[1]);
      u.push_back(v[3]);
      u.push_back(v[0]);
      u.push_back(v[2]);
    } else {
      for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0) u.push_back(v[i]);
      }
      for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 1) u.push_back(v[i]);
      }
    }
    for (int i = 0; i < u.size(); i++) {
      c = 'a' + u[i];
      for (int j = 0; j < a[(u[i])]; j++) {
        cout << c;
      }
    }
    printf("\n");
  }
}
