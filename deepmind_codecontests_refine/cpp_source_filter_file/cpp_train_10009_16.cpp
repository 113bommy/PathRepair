#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n][m];
  int south[n][m];
  int east[n][m];
  int ans[n][m];
  vector<pair<int, int>> south1;
  vector<pair<int, int>> east1;
  int east2[m];
  int south2[n];
  int eastmax[n];
  int southmax[m];
  for (long long int i = 0; i <= n - 1; i++) {
    for (long long int j = 0; j <= m - 1; j++) cin >> arr[i][j];
  }
  for (long long int i = 0; i <= n - 1; i++) {
    for (long long int j = 0; j <= m - 1; j++) {
      east[i][j] = 0;
      south[i][j] = 0;
    }
  }
  for (long long int i = 0; i <= n - 1; i++) {
    for (long long int j = 0; j <= m - 1; j++) {
      east1.push_back(make_pair(arr[i][j], j));
    }
    sort((east1).begin(), (east1).end());
    east2[0] = 1;
    int k = 1;
    for (long long int j = 1; j <= m - 1; j++) {
      if (east1[j].first != east1[j - 1].first) {
        east2[j] = ++k;
      } else {
        east2[j] = k;
      }
    }
    eastmax[i] = east2[m - 1];
    for (long long int j = 0; j <= m - 1; j++) {
      east[i][east1[j].second] = east2[j];
    }
    east1.clear();
  }
  for (long long int i = 0; i <= m - 1; i++) {
    for (long long int j = 0; j <= n - 1; j++) {
      south1.push_back(make_pair(arr[j][i], j));
    }
    sort((south1).begin(), (south1).end());
    south2[0] = 1;
    int k = 1;
    for (long long int j = 1; j <= n - 1; j++) {
      if (south1[j].first != south1[j - 1].first) {
        south2[j] = ++k;
      } else {
        south2[j] = k;
      }
    }
    southmax[i] = south2[n - 1];
    for (long long int j = 0; j <= n - 1; j++) {
      south[south1[j].second][i] = south2[j];
    }
    south1.clear();
  }
  for (long long int i = 0; i <= n - 1; i++) {
    for (long long int j = 0; j <= m - 1; j++) {
      if (east[i][j] >= south[i][j])
        ans[i][j] = max(southmax[i] + (east[i][j] - south[i][j]), eastmax[i]);
      else {
        ans[i][j] = max(southmax[j], eastmax[i] + (south[i][j] - east[i][j]));
      }
    }
  }
  for (long long int i = 0; i <= n - 1; i++) {
    for (long long int j = 0; j <= m - 1; j++) cout << ans[i][j] << " ";
    cout << "\n";
  }
}
