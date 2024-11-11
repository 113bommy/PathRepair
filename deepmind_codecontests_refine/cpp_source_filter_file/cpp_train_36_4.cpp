#include <bits/stdc++.h>
using namespace std;
const long long int mod = (1ll << 32);
int main() {
  int N;
  string s;
  cin >> N;
  cin >> s;
  int F = count(s.begin(), s.end(), 'F');
  int A = count(s.begin(), s.end(), 'A');
  int I = count(s.begin(), s.end(), 'I');
  if (!I) {
    cout << A << endl;
    return 0;
  } else if (I >= 2) {
    cout << "0" << endl;
    return 0;
  } else {
    cout << A << endl;
    return 0;
  }
  return 0;
}
