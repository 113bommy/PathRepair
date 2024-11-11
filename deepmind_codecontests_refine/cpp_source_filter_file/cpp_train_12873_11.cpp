#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  float k, n, s, p;
  cin >> k >> n >> s >> p;
  cout << ceil((ceil(n / s) * k) / p) << endl;
  return 0;
}
