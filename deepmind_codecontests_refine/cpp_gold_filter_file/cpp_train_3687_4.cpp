#include <bits/stdc++.h>
using namespace std;
const long long OO = 1e8;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
const int N = 100;
bool adjMatrixBool[N][N];
int adjMatrix[N][N];
vector<int> adjMatrixAll[N][N];
map<pair<int, int>, int> adjMatrixMap;
vector<vector<int> > adjList1;
vector<vector<pair<int, int> > > adjList2;
int main() {
  long long k, n;
  cin >> n >> k;
  vector<long long> v(k, 0);
  long long sum1 = 0, sum2 = 0;
  long long t;
  for (long long i = 0, j = 0; i < n; i++, j++) {
    cin >> t;
    j = j % k;
    v[j] += t;
  }
  long long min = 1e9, mini = 0;
  for (long long i = 0; i < k; i++)
    if (v[i] < min) {
      min = v[i];
      mini = i;
    }
  cout << mini + 1 << endl;
  return 0;
}
