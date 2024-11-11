#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<cstdlib>
using namespace std;

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  cout << (min(min(a, b), c) + min(d, e) - 50) << endl;
}