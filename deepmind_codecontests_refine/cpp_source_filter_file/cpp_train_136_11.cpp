#include <bits/stdc++.h>
using namespace std;
long long n, m, k, a, b, l, z, x_before;
long long start, end1, mid, sum = 0;
vector<long long> v1;
vector<long long> v2;
long long arr[9999999];
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  start = 1;
  end1 = n;
  while (start != end1) {
    long long mid = (start + end1) / 2;
    long long x = m * (mid + k);
    if (x >= (k * n)) {
      end1 = mid;
    } else {
      start = mid + 1;
    }
  }
  cout << end1 << endl;
}
