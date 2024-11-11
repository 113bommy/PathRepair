#include <bits/stdc++.h>
using namespace std;
long long N, M, K, P;
long long a[1005][1005];
long long rowVal[1005] = {0};
long long colVal[1005] = {0};
priority_queue<long long> rowQ;
priority_queue<long long> colQ;
vector<long long> row;
vector<long long> rowSum;
vector<long long> col;
vector<long long> colSum;
int main() {
  cin >> N >> M >> K >> P;
  for (long long i = 0; i < N; i++) {
    for (long long j = 0; j < M; j++) {
      cin >> a[i][j];
      rowVal[i] += a[i][j];
      colVal[j] += a[i][j];
    }
  }
  row.push_back(0);
  rowSum.push_back(0);
  for (long long i = 0; i < N; i++) rowQ.push(rowVal[i]);
  long long sum = 0;
  while (row.size() <= K) {
    sum += rowQ.top();
    row.push_back(rowQ.top());
    rowSum.push_back(sum);
    rowQ.push(rowQ.top() - M * P);
    rowQ.pop();
  }
  col.push_back(0);
  colSum.push_back(0);
  for (long long i = 0; i < M; i++) colQ.push(colVal[i]);
  sum = 0;
  while (col.size() <= K) {
    sum += colQ.top();
    col.push_back(colQ.top());
    colSum.push_back(sum);
    colQ.push(colQ.top() - N * P);
    colQ.pop();
  }
  if (0) {
    printf("Best rows & sums\n");
    for (long long i = 0; i <= K; i++) cout << row[i] << " ";
    cout << endl;
    for (long long i = 0; i <= K; i++) cout << rowSum[i] << " ";
    cout << endl;
    printf("\n");
    printf("Best cols\n");
    for (long long i = 0; i <= K; i++) cout << col[i] << " ";
    cout << endl;
    for (long long i = 0; i <= K; i++) cout << colSum[i] << " ";
    cout << endl;
    printf("\n\n\n");
  }
  long long best;
  for (long long i = 0; i <= K; i++) {
    long long j = K - i;
    if (i == 0)
      best = rowSum[i] + colSum[j] - i * j * P;
    else {
      best = max(best, rowSum[i] + colSum[j] - i * j * P);
    }
  }
  cout << best << endl;
}
