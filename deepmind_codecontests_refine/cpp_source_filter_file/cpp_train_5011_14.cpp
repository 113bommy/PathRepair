#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  string second;
  cin >> second;
  string str = second;
  long long x = INT_MAX;
  string ans;
  for (long long i = 0; i < 3; i++) {
    second = str;
    long long c = 0;
    char q;
    if (i == 0)
      q = 'G';
    else if (i == 1)
      q = 'R';
    else
      q = 'B';
    if (second[0] != q) {
      second[0] = q;
      c++;
    }
    for (long long j = 1; j < n; j++) {
      if (second[j] == second[j - 1]) {
        c++;
        if (j != n - 1) {
          if (second[j] == second[j + 1]) {
            if (second[j] == 'R')
              second[j] = 'G';
            else if (second[j] == 'G')
              second[j] = 'R';
            else
              second[j] = 'R';
          } else if (second[j] == 'R') {
            if (second[j + 1] == 'G')
              second[j] = 'B';
            else
              second[j] = 'G';
          } else if (second[j] == 'G') {
            if (second[j + 1] == 'B')
              second[j] = 'R';
            else
              second[j] = 'B';
          } else {
            if (second[j + 1] == 'R')
              second[j] = 'G';
            else
              second[j] = 'R';
          }
        } else {
          if (second[j] == 'R')
            second[j] = 'G';
          else if (second[j] == 'B')
            second[j] = 'G';
          else
            second[j] = 'R';
        }
      }
    }
    if (c < x) {
      x = c;
      ans = second;
    }
  }
  cout << x << endl << second << endl;
}
