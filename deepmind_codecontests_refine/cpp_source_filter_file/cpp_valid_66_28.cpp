#include <bits/stdc++.h>
const int N = 7 + 1e9;
using namespace std;
const int p = 1e3 + 10;
int arr[p];
int power(int x, int y);
void pre() {
  int j = 1;
  for (int i = 1; i < p; i++) {
    if (i % 3 != 0) {
      if (i % 10 != 3) {
        arr[j] = i;
        j++;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  pre();
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    cout << arr[n] << "\n";
  }
  return 0;
}
