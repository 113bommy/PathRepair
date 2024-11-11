#include <bits/stdc++.h>
char local = 'O';
using namespace std;
int main() {
  long long n;
  cin >> n;
  string s = "ABCD";
  for (long long i = 0; i < n; i++) cout << s[i % 4];
  cout << endl;
  return 0;
}
