#include<bits/stdc++.h>
using namespace std;
int main () {
  int N, M;
  cin >> N >> M;
  vector<int>A(N);
  int sum = 0;
  for (int i = 0; i < N; i ++) {
    cin >> A[i];
    sum += A[i];
  }
  sort(A.begin(), A.end());
  int k = A[N - M] * M * 4;
  cout << (k < sum ? "No" : "Yes") << endl;
}
