#include <bits/stdc++.h>
using namespace std;
bool isPrime[100000 + 1];
void sieve(int n) {
  memset(isPrime, true, sizeof isPrime);
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j = j + i) {
        isPrime[j] = false;
      }
    }
  }
}
vector<int> list_input;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sieve(100000);
  int k;
  cin >> k;
  if (k == 1) {
    cout << 1 << "\n";
  } else if (k == 2) {
    cout << 1 << "\n";
  } else {
    cout << 2 << "\n";
  }
  for (int i = 1; i < k + 1; ++i) {
    list_input.push_back(i + 1);
  }
  for (int j = 1; j < k + 1; ++j) {
    if (isPrime[j]) {
      cout << 1 << " ";
    } else {
      cout << 2 << " ";
    }
  }
}
