#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  long long n, t;
  vector<long long> a;
  vector<long long> x;
  vector<long long> ret;
  scanf("%lld %lld", &n, &t);
  for (long long i = 0; i < n; i++) {
    long long tmp;
    scanf("%lld", &tmp);
    a.push_back(tmp);
  }
  for (long long i = 0; i < n; i++) {
    long long tmp;
    scanf("%lld", &tmp);
    x.push_back(tmp);
  }
  for (long long i = 1; i < n; i++) {
    if (x[i] < x[i - 1] || x[i] < i + 1) {
      printf("No");
      return 0;
    }
  }
  for (long long i = 1; i < n - 1; i++) {
    if (x[i] < x[i + 1] && x[i] != i + 1) {
      printf("No");
      return 0;
    }
  }
  for (long long i = 0; i < n - 1; i++) {
    if (x[i] == i) {
      ret.push_back(a[i + 1] - 1);
    } else {
      ret.push_back(a[i + 1]);
    }
  }
  ret.push_back(ret[ret.size() - 1] + 1);
  for (long long i = 0; i < ret.size() - 1; i++) {
    if (ret[i] >= ret[i + 1]) {
      printf("No");
      return 0;
    }
  }
  printf("Yes\n");
  for (long long i = 0; i < ret.size(); i++) {
    printf("%lld ", ret[i] + t);
  }
  return 0;
}
