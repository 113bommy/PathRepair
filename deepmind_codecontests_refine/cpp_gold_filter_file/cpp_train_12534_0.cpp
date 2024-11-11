#include <bits/stdc++.h>
using namespace std;
bool prime[1000100];
int N;
struct num {
  long long n;
  int np;
};
num nums[10];
void pre() {
  prime[0] = prime[1] = false;
  for (int i = 2; i < 1000100; i++) prime[i] = true;
  for (int i = 2; i < 1000100; i++) {
    if (prime[i]) {
      for (int j = 2 * i; j < 1000100; j += i) prime[j] = false;
    }
  }
}
int numprime(long long k) {
  int cnt = 0;
  for (int i = 2; i < 1000100; i++) {
    if (prime[i]) {
      while (k % i == 0) {
        k /= i;
        cnt++;
      }
    }
  }
  if (k > 1) cnt++;
  return cnt;
}
bool cmp(num a, num b) { return a.n > b.n; }
int parent[10];
int best = 123123123;
long long Left[10];
int countnodes() {
  int total = 0;
  int numzeros = 0;
  for (int i = 1; i <= N; i++)
    if (parent[i] == 0) numzeros++;
  if (numzeros >= 2) total++;
  for (int i = 1; i <= N; i++) {
    if (nums[i].np == 1) continue;
    int cur = nums[i].np;
    for (int j = 1; j <= N; j++)
      if (parent[j] == i) cur -= nums[j].np;
    total += cur;
  }
  return total;
}
void Try(int n) {
  if (n == N + 1)
    best = min(best, countnodes());
  else {
    parent[n] = 0;
    Try(n + 1);
    for (int i = 1; i <= n - 1; i++) {
      if (Left[i] % nums[n].n == 0) {
        parent[n] = i;
        Left[i] /= nums[n].n;
        Try(n + 1);
        Left[i] *= nums[n].n;
      }
    }
  }
}
int main() {
  pre();
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> nums[i].n;
    nums[i].np = numprime(nums[i].n);
  }
  sort(nums + 1, nums + N + 1, cmp);
  for (int i = 1; i <= N; i++) Left[i] = nums[i].n;
  Try(1);
  cout << best + N;
  return 0;
}
