#include <bits/stdc++.h>
using namespace std;
int arr_freq[26];
int main() {
  long n, threes = 1, sevens = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    threes = (threes * 27) % 1000000007;
  }
  for (int i = 0; i < n; i++) {
    sevens = (sevens * 7) % 1000000007;
  }
  cout << (threes - sevens + 1000000007) % 1000000007;
}
