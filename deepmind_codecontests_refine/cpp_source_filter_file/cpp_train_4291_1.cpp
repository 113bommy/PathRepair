#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0;
  vector<int> v;
  int n;
  cin >> n;
  string s;
  cin >> s;
  int b = 0, w = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B')
      b++;
    else
      w++;
  }
  if (b == 0 && w == n)
    cout << "0";
  else if (w == 0 && b == n)
    cout << "0";
  else {
    char ch;
    if (s[0] == 'B')
      ch = 'W';
    else
      ch = 'B';
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != ch) {
        if (s[i] == 'B')
          s[i] = 'W';
        else
          s[i] = 'B';
        if (s[i + 1] == 'B')
          s[i + 1] = 'W';
        else
          s[i + 1] = 'B';
        v.push_back(i);
        c++;
      }
    }
    int b = 0, w = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B')
        b++;
      else
        w++;
    }
    if (b == 0 && w == n) {
      cout << c << endl;
      for (int i = 0; i < v.size(); i++) cout << v[i] + 1 << " ";
    } else if (w == 0 && b == n) {
      cout << c << endl;
      for (int i = 0; i < v.size(); i++) cout << v[i] + 1 << " ";
    } else {
      char ch;
      if (s[n - 1] == 'B')
        ch = 'W';
      else
        ch = 'B';
      for (int i = n - 1; i > 0; i--) {
        if (s[i] != ch) {
          if (s[i] == 'B')
            s[i] = 'W';
          else
            s[i] = 'B';
          if (s[i - 1] == 'B')
            s[i - 1] = 'W';
          else
            s[i - 1] = 'B';
          v.push_back(i - 1);
          c++;
        }
      }
      int b = 0, w = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'B')
          b++;
        else
          w++;
      }
      if (b == 0 && w == n) {
        cout << c << endl;
        for (int i = 0; i < v.size(); i++) cout << v[i] + 1 << " ";
      } else if (w == 0 && b == n) {
        cout << c << endl;
        for (int i = 0; i < v.size(); i++) cout << v[i] + 1 << " ";
      } else {
        char ch;
        if (s[0] == 'B')
          ch = 'W';
        else
          ch = 'B';
        for (int i = 0; i < n - 1; i++) {
          if (s[i] != ch) {
            if (s[i] == 'B')
              s[i] = 'W';
            else
              s[i] = 'B';
            if (s[i + 1] == 'B')
              s[i + 1] = 'W';
            else
              s[i + 1] = 'B';
            v.push_back(i);
            c++;
          }
        }
        int b = 0, w = 0;
        for (int i = 0; i < n; i++) {
          if (s[i] == 'B')
            b++;
          else
            w++;
        }
        if (b == 0 && w == n) {
          cout << c << endl;
          for (int i = 0; i < v.size(); i++) cout << v[i] + 1 << " ";
        } else if (w == 0 && b == n) {
          cout << c << endl;
          for (int i = 0; i < v.size(); i++) cout << v[i] + 1 << " ";
        } else
          cout << "-1";
      }
    }
  }
  cout << endl;
}
