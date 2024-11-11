#include <bits/stdc++.h>
using namespace std;
bool valid(char c) {
  switch (c) {
    case '_':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
      return true;
  }
  return false;
}
unsigned int valLen(string &s, unsigned int start) {
  for (unsigned int i = start; i < s.length(); i++)
    if (!valid(s[i])) return i - start;
  return s.length() - start;
}
int main() {
  string s;
  cin >> s;
  if (s.length() > 66) return cout << "NO", 0;
  unsigned int pos = valLen(s, 0);
  if (!pos || pos > 16 || pos == s.length() || s[pos] != '@')
    return cout << "NO", 0;
  int st = pos + 1;
  do {
    ++pos;
    int nextWordLen = valLen(s, pos);
    if (nextWordLen <= 0 || nextWordLen > 16) return cout << "NO", 0;
    pos += nextWordLen;
  } while (pos < s.length() && s[pos] == '.');
  if (pos - st > 32) return cout << "NO", 0;
  if (pos < s.length() &&
      (s[pos] != '/' ||
       (pos + 1 < s.length() || valLen(s, pos + 1) < s.length() - (pos + 1))))
    return cout << "NO", 0;
  return cout << "YES", 0;
}
