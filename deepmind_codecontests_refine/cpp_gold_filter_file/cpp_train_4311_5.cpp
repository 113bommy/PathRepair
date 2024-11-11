#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  float arr[26] = {0};
  set<char> s1;
  for (int i = 0; i < s.length(); i++) {
    s1.insert(s[i]);
    int x = s[i] - 97;
    arr[x]++;
  }
  if (s1.size() > n) {
    cout << "-1";
  } else {
    string r("");
    float x[26] = {0};
    for (int i = 0; i < 26; i++) {
      if (arr[i] > 0) {
        char z = i + 97;
        r += z;
        x[i]++;
      }
    }
    while (n > r.length()) {
      float maxval = 0;
      int index = 0;
      for (int i = 0; i < 26; i++) {
        if (arr[i] > 0) {
          float rz = (float)arr[i] / x[i];
          if (rz > maxval) {
            maxval = rz;
            index = i;
          }
        }
      }
      x[index]++;
      char z = index + 97;
      r += z;
    }
    int num = 0;
    for (int i = 0; i < 26; i++) {
      if (arr[i] > 0) {
        num = max((int)ceil(float(arr[i] / x[i])), num);
      }
    }
    cout << num << endl;
    cout << r;
  }
}
