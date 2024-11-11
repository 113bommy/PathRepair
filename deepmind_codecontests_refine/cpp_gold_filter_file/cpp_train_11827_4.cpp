#include <bits/stdc++.h>
using namespace std;
struct Good {
  long long order;
  long long cash;
};
struct Answer {
  long long MaxCash;
  long long Count;
};
Answer answer;
long long n, cash;
vector<long long> a;
bool compare(Good x, Good y) {
  if (x.cash + x.order == y.cash + y.order) {
    return (x.order < y.order);
  }
  return (x.cash + x.order < y.cash + y.order);
}
bool satisfied(long long k, vector<long long> a, long long cash) {
  for (int i = 0; i < n; i++) {
    a[i] = a[i] + (i + 1) * k;
  }
  sort(a.begin(), a.end());
  long long sum = 0;
  for (int i = 0; i < k; i++) {
    sum += a[i];
  }
  if (sum <= cash) {
    answer.Count = k;
    answer.MaxCash = sum;
  }
  return (sum <= cash);
}
void BinarySearch(vector<long long> a, long long cash) {
  long long left = 0;
  long long right = n;
  long long middle = (left + right + 1) / 2;
  while (left < right) {
    if (satisfied(middle, a, cash)) {
      left = middle;
    } else {
      right = middle - 1;
    }
    middle = (left + right + 1) / 2;
  }
}
int main() {
  scanf("%lld %lld", &n, &cash);
  a.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  BinarySearch(a, cash);
  printf("%lld %lld\n", answer.Count, answer.MaxCash);
  return 0;
}
