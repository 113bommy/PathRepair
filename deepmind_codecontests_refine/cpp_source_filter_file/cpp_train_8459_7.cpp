#include <bits/stdc++.h>
using namespace std;
int A(int a) {
  cout << "A " << a << endl;
  cout << flush;
  int temp;
  cin >> temp;
  return temp;
}
int B(int a) {
  cout << "B " << a << endl;
  cout << flush;
  int temp;
  cin >> temp;
  return temp;
}
void C(int a) {
  cout << "C " << a << endl;
  return;
}
int N;
int mid;
int midId;
vector<int> primes;
bool compound[100100];
void erat() {
  for (long long i = 2; i <= N; i++) {
    if (compound[i]) continue;
    primes.push_back(i);
    for (long long j = i * i; j <= N; j += i) compound[j] = true;
  }
}
int ALG1() {
  int begin = A(1);
  int start = midId;
  int end = -1;
  int cnt = 0;
  for (long long i = midId; i <= primes.size() - 1; i++) {
    int p = primes[i];
    cnt += B(p);
    if (cnt % 100 == 99) {
      if (A(1) != begin - cnt) {
        end = i;
        start = max(midId, end - 99);
        break;
      }
    }
  }
  if (end == -1) {
    end = primes.size() - 1;
    start = max(midId, end - 99);
  }
  assert(end - start < 101);
  for (long long i = start; i <= end; i++) {
    int p = primes[i];
    if (B(p) == 1) {
      return p;
    }
  }
  return 1;
}
void ALG2() {
  long long prod = 1;
  for (auto p : primes) {
    if (p > mid) break;
    if (prod * p > N) break;
    long long exprime = 1;
    while (1) {
      if (prod * exprime * p > N) break;
      if (B(exprime * p) == 0) break;
      exprime *= p;
    }
    prod *= exprime;
  }
  int other = ALG1();
  C(prod * other);
}
void solve() {
  cin >> N;
  if (N == 1) {
    C(1);
    return;
  }
  erat();
  mid = ceil(sqrt((double)N));
  int rmCnt = 0;
  for (long long i = 0; i < primes.size(); i++) {
    int p = primes[i];
    midId = i;
    if (p > mid) break;
    rmCnt += B(p);
  }
  int allCnt = A(1);
  if (allCnt + rmCnt == N)
    C(ALG1());
  else
    ALG2();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
