#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int counter[26];
int find(char it) {
  for (int i = 0; i < 26; i++) {
    if (it == alpha[i]) return i;
  }
  return -1;
}
int main() {
  int td_testCase;
  cin >> td_testCase;
  while (td_testCase--) {
    memset(counter, 0, sizeof(counter));
    int td_string;
    cin >> td_string;
    int save = td_string;
    while (td_string--) {
      string a;
      cin >> a;
      for (int i = 0; i < a.length(); i++) {
        counter[find(a[i])]++;
      }
    }
    bool possible = true;
    for (int i = 0; i < 26; i++) {
      if (counter[i] % save != 0) possible = false;
    }
    if (possible)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}
