#include <bits/stdc++.h>
using namespace std;
vector<pair<char, char> > a;
long long n;
char x;
bool ans;
int main() {
  cin >> n;
  a.resize(n << 1);
  for (int i = 0; i < (n << 1); i += 2)
    cin >> a[i].first >> a[i].second >> x >> a[i + 1].first >> a[i + 1].second;
  for (int i = 0; i < (n << 1); i++) {
    if (a[i].first == 'O', a[i].second == 'O') {
      a[i].first = '+';
      a[i].second = '+';
      ans = 1;
      break;
    }
  }
  if (ans == 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  for (int i = 0; i < (n << 1); i += 2)
    cout << endl
         << a[i].first << a[i].second << '|' << a[i + 1].first
         << a[i + 1].second;
}
