#include <bits/stdc++.h>
using namespace std;
long long arr[1000];
int main() {
  ios::sync_with_stdio(false);
  long long n, h;
  cin >> h >> n;
  int nn = n;
  for (int i = 0; i <= h; i++) {
    arr[i] = nn;
    nn = (nn / 2) + (nn & 1);
  }
  reverse(arr, arr + h + 1);
  long long count = 0;
  for (int i = 0; i < h; i++) {
    long long next = arr[i + 1];
    long long cur = arr[i];
    bool nextgoleft = (i == 0) ? true : (arr[i] == 2LL * arr[i - 1]);
    bool nextleft = (arr[i + 1] != 2LL * arr[i]);
    if (nextgoleft != nextleft) {
      count += (1LL << (h - i)) - 1;
    }
    count++;
  }
  cout << count << endl;
  cin.get();
  cin.get();
  return 0;
}
