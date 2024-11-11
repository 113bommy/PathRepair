#include <bits/stdc++.h>
using namespace std;
int main() {
  char a, b, c;
  cin >> a >> b;
  int n;
  cin >> n;
  if (a == '^') {
    int mod = n % 4;
    if (mod == 1) {
      if (b == '>')
        cout << "cw" << endl;
      else if (b == '<')
        cout << "ccw" << endl;
    } else if (mod == 3) {
      if (b == '>')
        cout << "ccw" << endl;
      else if (b == '<')
        cout << "cw" << endl;
    } else
      cout << "undefined" << endl;
  } else if (a == '<') {
    int mod = n % 4;
    if (mod == 1) {
      if (b == '^')
        cout << "cw" << endl;
      else if (b == 'v')
        cout << "ccw" << endl;
    } else if (mod == 3) {
      if (b == '^')
        cout << "ccw" << endl;
      else if (b == 'v')
        cout << "cw" << endl;
    } else
      cout << "undefined" << endl;
  }
  if (a == '>') {
    int mod = n % 4;
    if (mod == 1) {
      if (b == 'v')
        cout << "cw" << endl;
      else if (b == '^')
        cout << "ccw" << endl;
    } else if (mod == 3) {
      if (b == 'v')
        cout << "ccw" << endl;
      else if (b == '^')
        cout << "cw" << endl;
    } else
      cout << "undefined" << endl;
  } else if (a == 'v') {
    int mod = n % 4;
    if (mod == 1) {
      if (b == '<')
        cout << "cw" << endl;
      else if (b == '>')
        cout << "ccw" << endl;
    } else if (mod == 3) {
      if (b == '<')
        cout << "ccw" << endl;
      else if (b == '>')
        cout << "cw" << endl;
    } else
      cout << "undefined" << endl;
  }
}
