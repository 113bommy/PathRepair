#include <bits/stdc++.h>
using namespace std;
void shows(stack<char> gs) {
  stack<char> g = gs;
  while (!g.empty()) {
    cout << '\t' << g.top();
    g.pop();
  }
  cout << '\n';
}
int main() {
  string s, u;
  cin >> s;
  int arr[26] = {0};
  for (int i = 0; i < s.length(); i++) {
    arr[s[i] - 'a']++;
  }
  stack<char> t;
  for (int i = 0; i < s.length();) {
    int min = int(s[i]) - int('a');
    char min_char[1];
    for (int j = 0; j < min; j++) {
      if (arr[j] > 0) {
        min = j;
        break;
      }
    }
    min_char[0] = char(min + int('a'));
    if (!t.empty() && t.top() <= min_char[0]) {
      u += t.top();
      t.pop();
    } else {
      int k;
      for (k = i; s[k] != min_char[0]; k++) {
        t.push(s[k]);
        arr[s[k] - 'a']--;
      }
      u += s[k];
      i = k + 1;
      arr[s[k] - 'a']--;
    }
  }
  while (!t.empty()) {
    u += t.top();
    t.pop();
  }
  cout << u << endl;
}
