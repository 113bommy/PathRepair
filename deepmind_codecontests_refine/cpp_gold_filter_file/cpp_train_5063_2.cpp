#include <bits/stdc++.h>
using namespace std;
void secondPart(long long i, long long prev, long long k, int middle, int n) {
  long long start = 0;
  if (middle != 1 && i == 0) start = 1;
  for (long long j = start; j < (1LL << (n / 2)); j++) {
    long long rev = 0;
    for (int h = 1; h < n / 2; h++) {
      rev |= ((j & (1LL << h)) >> h) << (n / 2 - 1 - h);
    }
    if (j & 1) {
      if ((((~rev) & ((1LL << (n / 2 - 1)) - 1)) >= i) && middle != 1) {
        prev++;
      } else if (((~rev) & ((1LL << (n / 2 - 1)) - 1)) > i) {
        prev++;
      }
    } else {
      if (rev >= i) {
        prev++;
      } else if (rev > i) {
        prev++;
      }
    }
    if (prev == k) {
      for (int h = 0; h < n / 2; h++) {
        if (i & (1LL << (n / 2 - 1 - h)))
          cout << '1';
        else
          cout << '0';
      }
      if (middle == 1)
        cout << '1';
      else if (middle == 2)
        cout << '0';
      for (int h = 0; h < n / 2; h++) {
        if (j & (1LL << (n / 2 - 1 - h)))
          cout << '1';
        else
          cout << '0';
      }
      exit(0);
    }
  }
}
int main(int argc, char **argv) {
  int n;
  long long k, curr = 0;
  cin >> n >> k;
  if (n & 1) {
    n--;
    for (long long i = 0; i < (1LL << (n / 2 - 1)); i++) {
      long long prev = curr;
      if (i == 0) {
        curr += (((1LL << (n / 2 - 1)) - 1) - i + 1) * 2 - 1;
      } else {
        curr += (((1LL << (n / 2 - 1)) - 1) - i + 1) * 2;
      }
      if (curr >= k) {
        secondPart(i, prev, k, 2, n);
        break;
      }
      prev = curr;
      if (i == 0) {
        curr += (((1LL << (n / 2 - 1)) - 1) - i + 1) * 2 - 1;
      } else {
        curr += (((1LL << (n / 2 - 1)) - 1) - i + 1) * 2 - 1;
      }
      if (curr >= k) {
        secondPart(i, prev, k, 1, n);
        break;
      }
    }
  } else {
    for (long long i = 0; i < (1LL << (n / 2 - 1)); i++) {
      long long prev = curr;
      if (i == 0) {
        curr += (((1LL << (n / 2 - 1)) - 1) - i + 1) * 2 - 1;
      } else {
        curr += (((1LL << (n / 2 - 1)) - 1) - i + 1) * 2;
      }
      if (curr >= k) {
        secondPart(i, prev, k, 0, n);
        break;
      }
    }
  }
  cout << -1;
  return 0;
}
