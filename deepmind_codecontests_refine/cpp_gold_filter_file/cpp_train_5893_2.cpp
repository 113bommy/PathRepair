#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000006;
long long pmend[maxn], pmeni[maxn], pmayi[maxn], pmayd[maxn];
stack<int> P1, P;
int N, A[maxn];
void calcpmeni() {
  pmeni[1] = 1;
  pmayi[1] = 1;
  P.push(1);
  P1.push(1);
  for (int i = 2; i <= N; i++) {
    while (!P.empty() && A[P.top()] >= A[i]) P.pop();
    while (!P1.empty() && A[P1.top()] <= A[i]) P1.pop();
    if (P1.empty())
      pmayi[i] = 1;
    else
      pmayi[i] = P1.top() + 1;
    if (P.empty())
      pmeni[i] = 1;
    else
      pmeni[i] = P.top() + 1;
    P.push(i);
    P1.push(i);
  }
}
void calcpmend() {
  pmend[N] = N;
  pmayd[N] = N;
  while (!P1.empty()) P1.pop();
  while (!P.empty()) P.pop();
  P1.push(N);
  P.push(N);
  for (int i = N - 1; i >= 1; i--) {
    while (!P.empty() && A[P.top()] > A[i]) P.pop();
    while (!P1.empty() && A[P1.top()] < A[i]) P1.pop();
    if (P1.empty())
      pmayd[i] = N;
    else
      pmayd[i] = P1.top() - 1;
    if (P.empty())
      pmend[i] = N;
    else
      pmend[i] = P.top() - 1;
    P.push(i);
    P1.push(i);
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  calcpmeni();
  calcpmend();
  long long sol = 0;
  for (int i = 1; i <= N; i++) {
    sol = sol + A[i] * (i - pmayi[i] + 1) * (pmayd[i] - i + 1) -
          A[i] * (i - pmeni[i] + 1) * (pmend[i] - i + 1);
  }
  cout << sol;
  return 0;
}
