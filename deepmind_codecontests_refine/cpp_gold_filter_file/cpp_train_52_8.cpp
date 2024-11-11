#include <bits/stdc++.h>
using namespace std;
string s;
void kill() {
  cout << "Impossible";
  exit(0);
}
int po = 1, ne = 0;
void print(int a, int b) {
  cout << "Possible" << endl;
  char last = '+';
  int target1 = 0, cnt1 = 0;
  int target2 = 0, cnt2 = 0;
  if (po) {
    target1 = a / po;
    cnt1 = a % po;
  }
  if (ne) {
    target2 = b / ne;
    cnt2 = b % ne;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '=') {
      cout << s.substr(i);
      return;
    }
    if (s[i] == ' ') {
      cout << ' ';
      continue;
    }
    if (s[i] == '?') {
      if (last == '+') {
        if (cnt1) {
          cout << target1 + 1;
          cnt1--;
        } else {
          cout << target1;
        }
      } else {
        if (cnt2) {
          cout << target2 + 1;
          cnt2--;
        } else {
          cout << target2;
        }
      }
    } else {
      cout << s[i];
      last = s[i];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  getline(cin, s);
  int n = 0;
  int j = s.size() - 1, d = 1;
  while (s[j] != ' ') {
    n += d * (s[j] - '0');
    j--;
    d *= 10;
  }
  for (int i = 0; i < s.size() && s[i] != '='; i++) {
    if (s[i] == '?') continue;
    if (s[i] == ' ') continue;
    if (s[i] == '+')
      po++;
    else
      ne++;
  }
  if (po - ne == n) print(po, ne);
  if (po - ne > n) {
    int x = po - n;
    if (x > n * ne) kill();
    print(po, x);
  }
  if (po - ne < n) {
    int x = n + ne;
    if (x > n * po) kill();
    print(x, ne);
  }
  return 0;
}
