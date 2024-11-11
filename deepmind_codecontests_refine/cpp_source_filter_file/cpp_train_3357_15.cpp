#include <bits/stdc++.h>
using namespace std;
bool ab[100000000];
int ab1[1000000];
map<unsigned long long int, unsigned long long int> m;
map<unsigned long long int, unsigned long long int> m1;
map<unsigned long long int, unsigned long long int> m2;
vector<unsigned long long int> v;
vector<unsigned long long int> v1;
vector<unsigned long long int>::iterator itr;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s12;
  long long int a, b, d = 100000000000000, j = 0, i = 0, t, s = 0, s2, as, as1,
                      n = 50, c = 0, c2 = 1, l;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a > b) {
      cout << b << endl;
    } else if (a == b) {
      cout << b + 1 << endl;
    } else {
      if (b % a == 0) {
        c = 1;
      }
      cout << b + (b / (a - 1)) - c << endl;
      c = 0;
    }
  }
}
