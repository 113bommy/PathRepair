#include <bits/stdc++.h>
using namespace std;
double PI = 3.14159265359;
int a[1000005];
vector<int> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  long long cnt = 0;
  if (n % 2 == 0) {
    cnt += n / 2 - 1;
  } else {
    cnt += n;
  }
  cout << cnt;
  return 0;
}
