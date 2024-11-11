#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 1e6 + 10;
int P[maxn], F[maxm];
long long L[maxn];
bool mark[maxn];
vector<int> E[maxn];
queue<int> q;
set<int> se;
set<long long> lse;
char ch[maxn];
int n, m;
bool fond = true;
int main() {
  long long a;
  scanf("%lld%d", &a, &n);
  long long num = 0, ins = -1;
  long long mina = a;
  for (int i = 0; i < n; i++) {
    long long k;
    scanf("%lld", &k);
    if (mina >= a % k) {
      mina = a % k;
      num = a / k;
      ins = i + 1;
    }
  }
  cout << ins << " " << num << endl;
  return 0;
}
