#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, K;
  vector<long> A;
  cin >> N >> K;
  long tmp;
  for (long i = 0; i < N; i++) {
    cin >> tmp;
    A.push_back(tmp);
  }
  sort(A.begin(), A.begin() + N);
  if (K > N)
    cout << "-1";
  else
    cout << A[N - K] << " 0";
}
