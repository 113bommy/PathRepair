#include <bits/stdc++.h>
using namespace std;
unsigned long long maxn = 1e17;
unsigned long long res = 0;
long long a;
int main() {
  cin >> a;
  int sigema = maxn % a * 3 % a * 3 % a * 5 % a * 2 % a * 3 % a * 3 % a;
  cout << a - sigema << " " << ((unsigned long long)1e18 + a - sigema - 1);
}
