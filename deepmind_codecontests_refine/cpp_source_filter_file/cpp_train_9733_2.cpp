#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int Min[3], Max[3];
  for (int i = 0; i < 3; i++) cin >> Min[i] >> Max[i];
  cout << min(n - Min[1] - Min[2], Min[0]) << ' '
       << min(n - Min[2] - min(n - Min[1] - Min[2], Max[0]), Max[1]) << ' '
       << n - min(n - Min[1] - Min[2], Max[0]) -
              min(n - Min[2] - min(n - Min[1] - Min[2], Max[0]), Max[1]);
}
