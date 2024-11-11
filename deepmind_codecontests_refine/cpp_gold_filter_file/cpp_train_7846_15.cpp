#include <bits/stdc++.h>
using namespace std;
long long N, Total;
vector<long long> V;
void getDivs() {
  N /= 3;
  long long sqrt_n = sqrt(N);
  for (long long i = 2; i <= sqrt_n; i++)
    if ((N % i) == 0) V.push_back(i);
}
int sols(long long x, long long y, long long z) {
  if (x == y && y == z)
    return 1;
  else if (x == y || x == z || y == z)
    return 3;
  else
    return 6;
}
bool valid(long long x, long long y, long long z) {
  if (x * y * z != N) return false;
  if ((x + y - z) % 2 != 0) return false;
  if ((z + x - y) % 2 != 0) return false;
  if ((z + y - x) % 2 != 0) return false;
  long long a = (x + y - z) / 2;
  long long b = (z + x - y) / 2;
  long long c = (z + y - x) / 2;
  if (a <= 0 || b <= 0 || c <= 0) return false;
  return true;
}
void findTriplets() {
  long long x, y, z;
  for (int i = 0; i < V.size(); i++) {
    x = V[i];
    for (int j = i; x * V[j] * V[j] <= N && j < V.size(); j++) {
      y = V[j];
      if ((N % (x * y)) != 0) continue;
      z = N / (x * y);
      if (valid(x, y, z)) Total += sols(x, y, z);
    }
  }
}
int main() {
  cin >> N;
  if ((N % 3) != 0) {
    cout << "0";
    return 0;
  }
  getDivs();
  findTriplets();
  cout << Total;
  return 0;
}
