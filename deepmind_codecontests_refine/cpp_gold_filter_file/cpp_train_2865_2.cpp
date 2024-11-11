#include <bits/stdc++.h>
using namespace std;
int NeedleHayStack(const string &haystack, const string &needle) {
  if (needle.length() == 0 || needle.length() > haystack.length()) {
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
    int size = 0;
    int j = i;
    int pos = 0;
    while (haystack[j] == needle[pos] && pos < needle.length()) {
      pos = pos + 1;
      size = size + 1;
      j = j + 1;
    }
    if (size == needle.length()) {
      cnt++;
      i = i + needle.length() - 1;
    }
  }
  return cnt;
}
int main() {
  string needle, haystack;
  cin >> haystack;
  cin >> needle;
  int output = NeedleHayStack(haystack, needle);
  reverse(haystack.begin(), haystack.end());
  reverse(needle.begin(), needle.end());
  int output2 = NeedleHayStack(haystack, needle);
  cout << min(output, output2) << endl;
}
