#include <bits/stdc++.h>
using namespace std;
string s;
long long fastpow(int b, int e) {
  if (!e) return 1;
  if (e & 1) return b * fastpow(b, e - 1);
  long long temp = fastpow(b, e / 2);
  return temp * temp;
}
int notwork(char a, char b) {
  set<char> s;
  s.insert(a);
  s.insert(b);
  if (a == b && a == 'o') return 0;
  if (a == b && a == 'v') return 0;
  if (a == b && a == 'V') return 0;
  if (a == b && a == 'i') return 0;
  if (a == b && a == 'I') return 0;
  if (a == b && a == 'H') return 0;
  if (a == b && a == 'O') return 0;
  if (a == b && a == 'M') return 0;
  if (a == b && a == 'x') return 0;
  if (a == b && a == 'X') return 0;
  if (a == b && a == 'Y') return 0;
  if (a == b && a == 'w') return 0;
  if (a == b && a == 'W') return 0;
  if (a == b && a == 'U') return 0;
  if (a == b && a == 'T') return 0;
  if (s.count('b') && s.count('d')) return 0;
  if (s.count('p') && s.count('q')) return 0;
  return 1;
}
int midwork(char a) {
  char arr[] = {'U', 'T', 'W', 'w', 'Y', 'x', 'X', 'M',
                'o', 'O', 'H', 'i', 'I', 'v', 'V'};
  for (int i = 0; i < 15; i++)
    if (arr[i] == a) return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  int len = s.length();
  int mid = len / 2;
  if (s.length() & 1 == 0) mid++;
  if (len & 1) {
    if (!midwork(s[mid])) return cout << "NIE", 0;
  }
  for (int i = 0, j = len - 1; i < mid; i++, j--) {
    if (notwork(s[i], s[j])) return cout << "NIE", 0;
  }
  cout << "TAK";
  return 0;
}
