#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x;
  long long y;
};
struct compare {
  bool operator()(long long a, long long b) { return a > b; }
};
int main() {
  ios::sync_with_stdio(false);
  long long x, y, z;
  long long x1, y1, z1;
  long long a[7];
  cin >> x >> y >> z;
  cin >> x1 >> y1 >> z1;
  for (int i = 1; i <= 6; i++) cin >> a[i];
  long long sum = 0;
  if (z > z1)
    sum += a[4];
  else if (z < 0)
    sum += a[3];
  if (y > y1)
    sum += a[2];
  else if (y < 0)
    sum += a[1];
  if (x > x1)
    sum += a[6];
  else if (x < 0)
    sum += a[5];
  cout << sum << endl;
  return 0;
}
