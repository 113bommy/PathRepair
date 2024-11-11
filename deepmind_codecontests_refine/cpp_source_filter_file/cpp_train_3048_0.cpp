#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
const int lazy = int('a' - 'A');
const long long N = 1e7 + 1;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
long long sum = 0, final = 0, result = 0;
template <class T = int>
T scan() {
  T res;
  std::cin >> res;
  return res;
}
bool checkperfectsquare(int n) {
  if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
    return 1;
  } else {
    return 0;
  }
}
int invertBits(int num) {
  int x = log2(num) + 1;
  for (int i = 0; i < x; i++) num = (num ^ (1 << i));
  return num;
}
void it_was_me_dio_hahahahahaha() {
  long long a, b;
  cin >> a >> b;
  cout << (a ^ (a & b) + (b ^ (a & b)));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    it_was_me_dio_hahahahahaha();
  }
}
