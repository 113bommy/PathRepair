#include <bits/stdc++.h>
using namespace std;
int root(int arr[], int i) {
  while (arr[i] != i) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}
void Union(int arr[], int Size[], int a, int b) {
  int rootA = root(arr, a);
  int rootB = root(arr, b);
  if (Size[rootA] < Size[rootB]) {
    arr[rootA] = arr[rootB];
    Size[rootB] += Size[rootA];
  } else {
    arr[rootB] = arr[rootA];
    Size[rootA] += Size[rootB];
  }
}
bool findRoot(int a, int b, int arr[]) {
  if (root(arr, a) == root(arr, b))
    return true;
  else
    return false;
}
vector<vector<int> > adj(105);
bool nCyc = false;
int vis[55][55];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int a, b, c, cnt = 0, c2 = 0;
int dp[105][105];
string s1, s2;
int solve(int i, int val) { return 0; }
int freq[1000005], check[1000005];
int main() {
  int n, k;
  double sum = 0.0;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
  if (round((sum / (double)n)) == k)
    cout << 0;
  else {
    for (int i = 1; i < 1000000; i++) {
      double nSum = round((sum + (double)i * k));
      nSum /= (double)n + i;
      if (round(nSum) == k) {
        cout << i;
        return 0;
      }
    }
  }
  return 0;
}
