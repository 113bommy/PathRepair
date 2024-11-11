#include <bits/stdc++.h>
using namespace std;
int main() {
  char f[10];
  char s[10];
  gets(f);
  gets(s);
  if (strcmp(f, "sunday") == 0 && strcmp(s, "sunday") == 0 ||
      strcmp(f, "sunday") == 0 && strcmp(s, "tuesday") == 0 ||
      strcmp(f, "sunday") == 0 && strcmp(s, "wednesday") == 0) {
    cout << "YES" << endl;
    return 0;
  }
  if (strcmp(f, "monday") == 0 && strcmp(s, "monday") == 0 ||
      strcmp(f, "monday") == 0 && strcmp(s, "wednesday") == 0 ||
      strcmp(f, "monday") == 0 && strcmp(s, "thursday") == 0) {
    cout << "YES" << endl;
    return 0;
  }
  if (strcmp(f, "tuesday") == 0 && strcmp(s, "tuesday") == 0 ||
      strcmp(f, "tuesday") == 0 && strcmp(s, "thursday") == 0 ||
      strcmp(f, "tuesday") == 0 && strcmp(s, "friday") == 0) {
    cout << "YES" << endl;
    return 0;
  }
  if (strcmp(f, "wednesday") == 0 && strcmp(s, "wednesday") == 0 ||
      strcmp(f, "wednesday") == 0 && strcmp(s, "friday") == 0 ||
      strcmp(f, "wednesday") == 0 && strcmp(s, "saturday") == 0) {
    cout << "YES" << endl;
    return 0;
  }
  if (strcmp(f, "thursday") == 0 && strcmp(s, "thursday") == 0 ||
      strcmp(f, "thursday") == 0 && strcmp(s, "saturday") == 0 ||
      strcmp(f, "thursday") == 0 && strcmp(s, "sunday") == 0) {
    cout << "YES" << endl;
    return 0;
  }
  if (strcmp(f, "friday") == 0 && strcmp(s, "friday") == 0 ||
      strcmp(f, "friday") == 0 && strcmp(s, "monday") == 0 ||
      strcmp(f, "friday") == 0 && strcmp(s, "sunday") == 0) {
    cout << "YES" << endl;
    return 0;
  }
  if (strcmp(f, "saturday") == 0 && strcmp(s, "saturday") == 0 ||
      strcmp(f, "saturday") == 0 && strcmp(s, "monday") == 0 ||
      strcmp(f, "saturday") == 0 && strcmp(s, "tuesday") == 0) {
    cout << "YES" << endl;
    return 0;
  } else
    cout << "NO" << endl;
}
