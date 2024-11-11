#include <bits/stdc++.h>
using namespace std;
int main() {
  long int i, n, a[26] = {0}, b[26] = {0}, flag = 0, k, j, curr, count = 0,
                 swap[100] = {0}, pos, startindex[100] = {0};
  string s, t;
  cin >> n;
  cin >> s >> t;
  for (i = 0; i < n; i++) {
    a[s[i] - 97]++;
    b[t[i] - 97]++;
  }
  for (i = 0; i < 26; i++) {
    if (a[i] == b[i])
      continue;
    else {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
    cout << "-1\n";
  else if (s.compare(t) == 0)
    cout << "0\n";
  else {
    k = n - 1;
    curr = 0;
    for (int i = n - 1, j = n - 1; i >= 0;) {
      pos = 0;
      flag = 1;
      k = i;
      while (k >= 0 && s[k] != t[j]) {
        k--;
        flag = 2;
        pos++;
      }
      if (flag == 2) {
        swap[curr] = pos;
        startindex[curr] = k;
        while (pos > 0) {
          char temp = s[k];
          s[k] = s[k + 1];
          s[k + 1] = temp;
          k++;
          pos--;
        }
        curr++;
      }
      if (s[i] == t[j]) {
        i--;
        j--;
      }
    }
    for (i = 0; i <= curr; i++) {
      if (swap[i]) {
        count = count + swap[i];
      }
    }
    cout << count << "\n";
    for (i = 0; i <= curr; i++) {
      if (swap[i]) {
        j = startindex[i];
        while (swap[i] > 0) {
          cout << j + 1 << " ";
          j++;
          swap[i]--;
        }
      }
    }
  }
  return 0;
}
