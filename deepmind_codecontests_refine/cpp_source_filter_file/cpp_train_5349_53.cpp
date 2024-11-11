#include <bits/stdc++.h>
using namespace std;
long long MOD = 1791791791;
double eps = 1e-12;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T, typename U, typename V>
struct Triple {
  T first;
  U second;
  V third;
  Triple(T first, U second, V third)
      : first(first), second(second), third(third) {}
  Triple() {}
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  s[0] = tolower(s[0]);
  cout << s << endl;
}
