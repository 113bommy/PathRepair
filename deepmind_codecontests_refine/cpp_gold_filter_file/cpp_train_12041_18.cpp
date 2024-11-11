#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int dx1[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy1[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
const double eps = 1e-9;
const int inf = 2000000000;
const long long int infLL = 9000000000000000000;
const long long int MOD = 1e+7;
const double PI = 3.141592653589793238462643383279;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  std ::cin >> n;
  if (n <= 5) {
    cout << "-1\n";
    for (long long int i = 2; i < n + 1; i++) cout << "1 " << i << endl;
  } else {
    for (long long int i = 2; i < n - 1; i++) cout << "1 " << i << endl;
    cout << n - 2 << " " << n - 1 << endl;
    cout << n - 2 << " " << n << endl;
    for (long long int i = 2; i < n + 1; i++) cout << "1 " << i << endl;
  }
  return 0;
}
