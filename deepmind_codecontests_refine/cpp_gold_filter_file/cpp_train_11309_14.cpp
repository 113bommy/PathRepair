#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g1;
vector<int> g;
vector<pair<int, pair<int, int> > > g2;
vector<string> s1;
int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  long long x = 0;
  long long n1 = n;
  while (n1 - (a * x) >= 0) {
    n = n1;
    n = n - a * x;
    ;
    if (n % b == 0) {
      cout << "YES" << endl;
      cout << x << " " << n / b;
      return 0;
    }
    x++;
  }
  cout << "NO";
  return 0;
}
