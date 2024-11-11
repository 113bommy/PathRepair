#include <bits/stdc++.h>
using namespace std;
string second;
void Or(int num) {
  int i = 9;
  while (num) {
    int ch = num % 2;
    num /= 2;
    if (ch == 1) second[i] = '1';
    i--;
  }
}
void And(int num) {
  int i = 9;
  while (i) {
    int ch = num % 2;
    num /= 2;
    if (ch == 0) second[i] = '0';
    i--;
  }
}
void Xor(int num) {
  int i = 9;
  while (num) {
    int ch = num % 2;
    num /= 2;
    if (ch == 1) {
      if (second[i] == '0')
        second[i] = '1';
      else if (second[i] == '1')
        second[i] = '0';
      else if (second[i] == 't')
        second[i] = 'x';
      else
        second[i] = 't';
    }
    i--;
  }
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  int n;
  cin >> n;
  for (int i = 0; i < 9; i++) {
    second.push_back('x');
  }
  for (int i = 0; i < n; i++) {
    string s2;
    int num;
    cin >> s2 >> num;
    if (s2[0] == '|')
      Or(num);
    else if (s2[0] == '&')
      And(num);
    else
      Xor(num);
  }
  cout << 2 << endl;
  cout << '|' << ' ';
  int ans = 0, two = 1;
  for (int i = 9; i >= 0; i--) {
    if (second[i] == '0' || second[i] == '1') ans += two;
    two *= 2;
  }
  cout << ans << endl;
  cout << '^' << ' ';
  ans = 0, two = 1;
  for (int i = 9; i >= 0; i--) {
    if (second[i] == 't' || second[i] == '0') ans += two;
    two *= 2;
  }
  cout << ans << endl;
}
