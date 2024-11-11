#include <bits/stdc++.h>
using namespace std;
bool checkBit(long long int n, long long int i) { return (n & (1LL << i)); }
long long int setBit(long long int n, long long int i) {
  return (n | (1LL << i));
}
long long int resetBit(long long int n, long long int i) {
  return (n & (~(1LL << i)));
}
void solve() {
  long long int n;
  cin >> n;
  n *= n;
  n--;
  if (n % 2) {
    cout << "white"
         << "\n";
    cout << "1 2"
         << "\n";
  } else {
    cout << "black"
         << "\n";
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
