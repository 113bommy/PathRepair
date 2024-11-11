#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100, PI = 3.14159265359;
map<long long, bool> ma, mb;
long long a[N];
pair<int, int> p[N];
vector<int> v, v1;
set<string> s;
int main() {
  long long n, min1, min2, min3, max1, max2, max3;
  cin >> n >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;
  n = n - min1 - min2 - min3;
  long long a1 = max1 - min1;
  for (int i = 0; i < a1; i++) {
    if (n == 0) {
      cout << min1 << " " << min2 << " " << min3;
      return 0;
    }
    n--;
    min1++;
  }
  a1 = max2 - min2;
  for (int i = 0; i < a1; i++) {
    if (n == 0) {
      cout << min1 << " " << min2 << " " << min3;
      return 0;
    }
    n--;
    min2++;
  }
  a1 = max3 - min3;
  for (int i = 0; i < a1; i++) {
    if (n == 0) {
      cout << min1 << " " << min2 << " " << min3;
      return 0;
    }
    n--;
    min3++;
  }
  cout << min1 << " " << min2 << " " << min3;
  return 0;
}
