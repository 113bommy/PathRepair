#include <bits/stdc++.h>
using namespace std;
long long arr[100010];
int main() {
  cin.sync_with_stdio(false);
  long long P, N, K;
  cin >> N >> K >> P;
  multiset<long long> S;
  for (int i = 0; i < N; ++i) cin >> arr[i];
  long long i = N - 2;
  long long sum = 0;
  long long mi = N;
  while (i >= 0 && K > 0) {
    K--;
    sum += arr[i];
    S.insert(arr[i]);
    i--;
  }
  if (sum > P) mi = min(mi, i + 2);
  while (i >= 0) {
    sum -= *S.begin();
    sum += arr[i];
    S.erase(S.begin());
    S.insert(arr[i]);
    i--;
    if (sum > P) mi = i + 2;
  }
  cout << mi << endl;
  return 0;
}
