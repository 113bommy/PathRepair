#include <bits/stdc++.h>
using namespace std;
int N, K;
long long A[200005], Ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  for (int i = 0; i <= N - 1; i++) cin >> A[i];
  priority_queue<long long, vector<long long> > pq;
  string str;
  cin >> str;
  int Bi = str[0] - 'a';
  int prv = Bi;
  for (int i = 1; i <= N - 1; i++) {
    Bi = str[i] - 'a';
    if (Bi != prv) {
      int Cnt = 0;
      while (!pq.empty()) {
        if (Cnt < K) {
          Ans += pq.top();
          Cnt++;
        }
        pq.pop();
      }
    }
    pq.push(A[i]);
    prv = Bi;
  }
  int Cnt = 0;
  while (!pq.empty()) {
    if (Cnt < K) {
      Ans += pq.top();
      Cnt++;
    }
    pq.pop();
  }
  cout << Ans << '\n';
  return 0;
}
