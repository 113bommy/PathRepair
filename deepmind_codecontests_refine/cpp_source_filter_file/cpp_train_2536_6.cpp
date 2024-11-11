#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  string s;
  cin >> s;
  string res = "";
  int start = 0;
  if (s.substr(start, 3) == "ftp") {
    res += "ftp://";
    start = 3;
  } else {
    res += "http://";
    start = 4;
  }
  int end = start;
  while (s.substr(end, 2) != "ru") {
    end++;
  }
  res += s.substr(start, end - start);
  res += ".ru";
  if (end != s.length() - 2) {
    res += "/";
    res += s.substr(end + 2, s.length() - end - 2);
  }
  cout << res;
  return 0;
}
