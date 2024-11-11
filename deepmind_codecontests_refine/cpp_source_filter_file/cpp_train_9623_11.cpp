#include <bits/stdc++.h>
using namespace std;
int casos;
int n;
int xors[1000100];
int main() {
  cin.tie(0), ios_base::sync_with_stdio(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n + 5; i++) {
    xors[i] = i ^ xors[i - 1];
  }
  int xx = 0;
  for (int i = 1; i <= n; i++) {
    int completas = n / i;
    if (completas % 2 == 0) {
      xx ^= xors[(n + 1) % i];
    } else {
      xx ^= (xors[i - 1] ^ xors[(n) % i]);
    }
  }
  while (n--) {
    int temp;
    cin >> temp;
    xx ^= temp;
  }
  cout << xx << "\n";
  return 0;
}
