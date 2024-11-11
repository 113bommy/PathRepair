#include <bits/stdc++.h>
using namespace std;
int num[300005];
int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> num[i];
  long long w = 0, b = 0;
  for (int i = 1; i <= N; i++) {
    if (num[i] % 2) {
      w += (num[i] + 1) / 2;
      b += num[i] / 2;
    } else {
      w += num[i] / 2;
      b += (num[i] + 1) / 2;
    }
  }
  cout << min(w, b);
}
