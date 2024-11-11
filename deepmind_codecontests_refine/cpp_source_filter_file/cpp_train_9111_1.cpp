#include <bits/stdc++.h>
using namespace std;
bool tag[2000009];
map<long long int, long long int> M, P;
long long int arr[1009];
vector<long long int> V[1009];
void sieve() {
  tag[0] = tag[1] = 1;
  for (long long int i = 4; i < 2000009; i = i + 2) tag[i] = 1;
  long long int root = sqrt(2000009) + 1;
  for (long long int i = 3; i <= root; i = i + 2) {
    if (tag[i] == 0) {
      for (long long int j = i * i; j < 2000009; j = j + i + i) tag[j] = 1;
    }
  }
  for (long long int i = 1; i < 2000009; i++) {
    if (tag[i] == 0) M[i] = 1;
  }
}
long long int check(long long int i, long long int j) {
  map<long long int, long long int>::iterator it;
  for (it = P.begin(); it != P.end(); it++) {
    if (M[it->first + arr[j]] != 1) return 0;
  }
  return 1;
}
int main() {
  long long int i, j, k, n, mx = 1, indx = 1, cnt;
  sieve();
  cin >> n;
  for (i = 1; i <= n; i++) cin >> arr[i];
  for (i = 1; i <= n; i++) {
    long long int jor = 0, bijor = 0;
    V[i].push_back(arr[i]);
    cnt = 1;
    P[arr[i]] = 1;
    for (j = i + 1; j <= n; j++) {
      if (i == j) continue;
      if (M[arr[i] + arr[j]] == 1) {
        long long int flag = check(i, j);
        if (flag) {
          V[i].push_back(arr[j]);
          P[arr[j]] = 1;
          cnt++;
          if (cnt > mx) {
            mx = cnt;
            indx = i;
          }
        }
      }
    }
    P.clear();
  }
  cout << mx << endl;
  for (i = 0; i < V[indx].size(); i++) cout << V[indx][i] << " ";
  cout << endl;
  return 0;
}
