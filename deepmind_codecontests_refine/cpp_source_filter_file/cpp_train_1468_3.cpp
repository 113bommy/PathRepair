#include <bits/stdc++.h>
using namespace std;
bool isvo(char ch) {
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string second;
  cin >> second;
  int i;
  bool p = 0;
  for (i = 1; i < second.size(); i++) {
    if (!isvo(second[i - 1]) && (second[i - 1] != 'n'))
      p = p | (!isvo(second[i]));
  }
  if (p)
    cout << "NO";
  else if (second.size() == 1 && (isvo(second[0]) || second[0] == 'n'))
    cout << "YES";
  else if (second.size() == 1)
    cout << "NO";
  else if (!isvo(second[second.size() - 1]) && second[second.size() - 1] == 'n')
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
