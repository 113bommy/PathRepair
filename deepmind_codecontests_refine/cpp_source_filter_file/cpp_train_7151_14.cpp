#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int size = s.size();
  if (size < 3) {
    cout << "No";
    return 0;
  }
  size -= 2;
  for (int i = 0; i < size; i++) {
    int a = 0, b = 0, c = 0;
    if (s[i] == 'A' || s[i + 1] == 'A' || s[i + 2] == 'A') a++;
    if (s[i] == 'B' || s[i + 1] == 'B' || s[i + 2] == 'C') b++;
    if (s[i] == 'C' || s[i + 1] == 'C' || s[i + 2] == 'C') c++;
    if (a && b && c) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
