#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
int n;
string a = "";
char c = 'a';
int main() {
  cin >> n;
  while (n > 0) {
    a += c;
    n--;
    if (n >= 1) a += c, n--;
    if (c + 1 > 'c') c = 'a' - 1;
    c++;
  }
  cout << a;
}
