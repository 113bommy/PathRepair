#include <bits/stdc++.h>
using namespace std;
bool siv[100000];
vector<long long> prime;
void sieve();
void pri();
long long int fact(long long int n);
int main() {
  int p;
  cin >> p;
  int need = p - 10;
  int n = 12;
  int have[12] = {0, 1, 4, 4, 4, 4, 4, 4, 4, 4, 15, 1};
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (need == i) {
      ans = have[i];
    }
  }
  cout << ans << endl;
}
void sieve() {
  memset(siv, true, sizeof(siv));
  int root = sqrt(100000);
  for (int i = 2; i <= root; i++) {
    for (int j = i * 2; j <= 100000; j += i) {
      siv[j] = false;
    }
  }
}
void pri() {
  sieve();
  siv[0] = false;
  siv[1] = false;
  for (int i = 0; i < 100000; i++)
    if (siv[i] == true) prime.push_back(i);
}
long long int fact(long long int n) {
  long long int ans = 1;
  for (long long int i = 1; i <= n; i++) {
    ans *= i;
  }
  return ans;
}
