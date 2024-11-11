#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MAX = 1000007;
const int MAX1 = 2007;
const int MAX2 = 4007;
const int LEN = 21;
const int BASE = 1000000000;
const double EPS = 1e-7;
const int MOD = 1234567891;
vector<int> nums;
map<int, int> MP;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = (0); i < (n); ++i) {
    int tmp;
    cin >> tmp;
    ++MP[tmp];
  }
  int ct = 0;
  for (int i = (0); i < (3005); ++i) {
    while (MP[i] > 1) {
      --MP[i];
      ++MP[i + 1];
      ++ct;
    }
  }
  cout << ct << endl;
  return 0;
}
