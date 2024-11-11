#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long int ans = 0;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  ans += a / b;
  return gcd(b, a % b);
}
long long int mod = 1000000007;
long long int binpower(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
bool isPrime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int test = 1;
  while (test--) {
    int n;
    cin >> n;
    string s;
    vector<string> alls;
    alls.push_back("Anka");
    alls.push_back("Chapay");
    alls.push_back("Cleo");
    alls.push_back("Troll");
    alls.push_back("Dracul");
    alls.push_back("Snowy");
    alls.push_back("Hexadecimal");
    int prev = -1;
    vector<vector<int> > adj(7);
    for (int i = 0; i < 3 * n; i++) {
      cin >> s;
      if (i % 3 == 1) continue;
      if (i % 3 == 0) {
        for (int j = 0; j < 7; j++) {
          if (alls[j] == s) {
            prev = j;
            break;
          }
        }
        continue;
      }
      if (i % 3 == 2) {
        for (int j = 0; j < 7; j++) {
          if (alls[j] == s) {
            adj[prev].push_back(j);
            prev = -1;
            break;
          }
        }
        continue;
      }
    }
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int mini = 1000000007;
    long long int pera, perb, perc;
    for (int i = 1; i < 6; ++i) {
      pera = a / i;
      for (int j = 1; j <= 7 - i - 1; ++j) {
        perb = b / j;
        perc = c / (7 - i - j);
        long long int ma, mi;
        ma = max(pera, max(perb, perc));
        mi = min(pera, min(perb, perc));
        mini = min(mini, ma - mi);
      }
    }
    cout << mini << " ";
    vector<vector<int> > v(50);
    int index = 0;
    for (int i = 1; i < 6; ++i) {
      pera = a / i;
      for (int j = 1; j <= 7 - i - 1; ++j) {
        perb = b / j;
        perc = c / (7 - i - j);
        long long int ma, mi;
        ma = max(pera, max(perb, perc));
        mi = min(pera, min(perb, perc));
        if (ma - mi == mini) {
          v[index].push_back(i);
          v[index].push_back(j);
          v[index].push_back(7 - i - j);
          index++;
        }
      }
    }
    int arr[7];
    for (int i = 0; i < 7; i++) arr[i] = i;
    int maxilike = 0;
    for (int i = 0; i < index; i++) {
      do {
        int curr = 0;
        for (int j = 0; j < v[i][0]; j++) {
          for (int k = 0; k < v[i][0]; k++) {
            if (k == j) continue;
            if (find(adj[arr[j]].begin(), adj[arr[j]].end(), arr[k]) !=
                adj[arr[j]].end())
              curr++;
          }
        }
        for (int j = v[i][0]; j < v[i][1] + v[i][0]; j++) {
          for (int k = v[i][0]; k < v[i][1] + v[i][0]; k++) {
            if (k == j) continue;
            if (find(adj[arr[j]].begin(), adj[arr[j]].end(), arr[k]) !=
                adj[arr[j]].end())
              curr++;
          }
        }
        for (int j = v[i][1] + v[i][0]; j < v[i][2] + v[i][1] + v[i][0]; j++) {
          for (int k = v[i][0] + v[i][1]; k < v[i][1] + v[i][0] + v[i][2];
               k++) {
            if (k == j) continue;
            if (find(adj[arr[j]].begin(), adj[arr[j]].end(), arr[k]) !=
                adj[arr[j]].end())
              curr++;
          }
        }
        maxilike = max(maxilike, curr);
      } while (next_permutation(arr, arr + 7));
    }
    cout << maxilike << endl;
  }
  return 0;
}
