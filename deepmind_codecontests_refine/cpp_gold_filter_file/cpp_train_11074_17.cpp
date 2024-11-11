#include <bits/stdc++.h>
using namespace std;
bool isPrime[1000011];
void sieve() {
  int N = 1000011;
  for (int i = 0; i <= N; i++) isPrime[i] = true;
  isPrime[0] = 0;
  isPrime[1] = 0;
  for (int i = 2; i * i <= N; i++) {
    if (isPrime[i] == true) {
      for (int j = i * i; j <= N; j += i) isPrime[j] = false;
    }
  }
}
int main() {
  sieve();
  int n, m, c1 = 0, c2 = 0;
  vector<int> v1;
  vector<int> v2;
  cin >> n >> m;
  int arr[n][m], temp;
  for (int i = 0; i < n; i++) {
    c2 = 0;
    for (int j = 0; j < m; j++) {
      c1 = 0;
      cin >> arr[i][j];
      temp = arr[i][j];
      if (!isPrime[temp]) {
        while (!isPrime[temp]) {
          temp++;
          c1++;
          c2++;
        }
      }
      v1.push_back(c1);
    }
    v2.push_back(c2);
  }
  for (int j = 0; j < m; j++) {
    c2 = 0;
    for (int i = 0; i < n; i++) {
      c1 = 0;
      temp = arr[i][j];
      if (temp) {
        while (!isPrime[temp]) {
          temp++;
          c1++;
          c2++;
        }
      }
      v1.push_back(c1);
    }
    v2.push_back(c2);
  }
  sort(v2.begin(), v2.end());
  cout << v2[0] << endl;
}
