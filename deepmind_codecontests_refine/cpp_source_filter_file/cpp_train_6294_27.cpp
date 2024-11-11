#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[3], ch1, ch2, ch3;
  for (int i = 0; i < 3; i++) {
    cin >> ch1 >> ch2 >> ch3;
    if (ch1 == 'A' && ch3 == 'B') a[0] = ch2;
    if (ch1 == 'B' && ch3 == 'A')
      if (ch2 = '>')
        a[0] = '<';
      else
        a[0] = '>';
    if (ch1 == 'A' && ch3 == 'C') a[2] = ch2;
    if (ch1 == 'C' && ch3 == 'A')
      if (ch2 = '>')
        a[2] = '<';
      else
        a[2] = '>';
    if (ch1 == 'B' && ch3 == 'C') a[1] = ch2;
    if (ch1 == 'C' && ch3 == 'B')
      if (ch2 = '>')
        a[1] = '<';
      else
        a[1] = '>';
  }
  if (a[0] == '<' && a[1] == '<' && a[2] == '<') cout << "ABC";
  if (a[0] == '<' && a[1] == '<' && a[2] == '>') cout << "Impossible";
  if (a[0] == '<' && a[1] == '>' && a[2] == '<') cout << "ACB";
  if (a[0] == '<' && a[1] == '>' && a[2] == '>') cout << "CAB";
  if (a[0] == '>' && a[1] == '<' && a[2] == '<') cout << "BAC";
  if (a[0] == '>' && a[1] == '<' && a[2] == '>') cout << "BCA";
  if (a[0] == '>' && a[1] == '>' && a[2] == '<') cout << "Impossible";
  if (a[0] == '>' && a[1] == '>' && a[2] == '>') cout << "CBA";
  return 0;
}
