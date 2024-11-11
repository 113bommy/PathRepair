#include <bits/stdc++.h>
using namespace std;
long long n, l, r;
vector<long long> divs;
int main() {
  scanf("%lld %lld %lld", &n, &l, &r);
  if (n == 0) {
    printf("0\n");
  } else {
    int aux = n;
    while (aux > 1) {
      divs.push_back(aux);
      aux /= 2;
    }
    vector<long long> mults;
    long long mult = 3;
    for (int i = (int)divs.size() - 1; i >= 0; i--) {
      if (divs[i] % 2 == 0) mults.push_back(mult);
      mult *= 2;
      mult++;
    }
    int sol = r - l + 1;
    for (long long i = l; i <= r; i++) {
      bool valid = false;
      for (int j = 0; j < (int)mults.size(); j++)
        if ((i - (mults[j] / 2) - 1) % (mults[j] + 1) == 0) valid = true;
      if (valid) sol--;
    }
    printf("%d\n", sol);
  }
  return 0;
}
