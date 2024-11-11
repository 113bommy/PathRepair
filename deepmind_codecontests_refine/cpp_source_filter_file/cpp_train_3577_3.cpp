#include <bits/stdc++.h>
using namespace std;
const long long MAX = 9999999999999999;
int queries, order;
vector<long long> graphSize;
vector<long long> aToFirst, aToLast, bToFirst, bToLast;
void countLength(vector<long long> &toFirst, vector<long long> &toLast,
                 long long v, int n) {
  if (n == 0) {
    toFirst[0] = 0;
    toLast[0] = 0;
    return;
  }
  if (n == 1) {
    toFirst[1] = v == 2;
    toLast[1] = v == 1;
    return;
  }
  if (v <= graphSize[n - 1]) {
    countLength(toFirst, toLast, v, n - 1);
    toFirst[n] = min(toFirst[n - 1], toLast[n - 1] + 3);
    toLast[n] = min(toFirst[n - 1], toLast[n - 1]) + (n - 1) / 2 + 1;
  } else {
    countLength(toFirst, toLast, v - graphSize[n - 1], n - 2);
    toFirst[n] = toFirst[n - 2] + 1;
    toLast[n] = toLast[n - 2];
  }
}
long long findMinLength(long long a, long long b, int n) {
  if (a == b) return 0;
  if (n <= 2) return 1;
  if (a <= graphSize[n - 1]) {
    if (b >= graphSize[n - 1] + 1) {
      return min(aToFirst[n - 1], aToLast[n - 1]) + bToFirst[n - 2] + 1;
    } else {
      long long d1 = min(aToFirst[n - 1] + bToLast[n - 1] + 2,
                         aToLast[n - 1] + bToFirst[n - 1] + 2);
      return min(d1, findMinLength(a, b, n - 1));
    }
  } else {
    return findMinLength(a - graphSize[n - 1], b - graphSize[n - 1], n - 2);
  }
}
int main() {
  cin >> queries >> order;
  graphSize.push_back(1);
  graphSize.push_back(2);
  int iMax = 2;
  for (; graphSize.back() < MAX; ++iMax) {
    graphSize.push_back(graphSize[iMax - 1] + graphSize[iMax - 2]);
  }
  for (int i = 1; i <= queries; ++i) {
    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    aToFirst.resize(min(order, iMax) + 1);
    aToLast.resize(min(order, iMax) + 1);
    bToFirst.resize(min(order, iMax) + 1);
    bToLast.resize(min(order, iMax) + 1);
    countLength(aToFirst, aToLast, a, min(order, iMax));
    countLength(bToFirst, bToLast, b, min(order, iMax));
    cout << findMinLength(a, b, min(order, iMax)) << endl;
  }
  return 0;
}
