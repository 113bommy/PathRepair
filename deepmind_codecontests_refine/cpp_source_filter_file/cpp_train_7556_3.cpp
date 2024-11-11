#include <bits/stdc++.h>
using namespace std;
ifstream in("file.in");
ofstream out("file.out");
struct comp {
  bool operator()(int a, int b) { return a > b; }
};
int n, first, c, t;
int main() {
  ios_base ::sync_with_stdio(0);
  cin >> n;
  first = 1;
  t = n;
  while (n) {
    c = n % 10;
    n /= 10;
    first *= 10;
  }
  first /= 10;
  first *= (c + 1);
  cout << first - t;
}
