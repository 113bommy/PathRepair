#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long arr[n][m];
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (long long j = 0; j < m; j++) {
      arr[i][j] = (long long)s[j] - 48;
    }
  }
  long long ops = 0;
  vector<long long> out;
  for (long long i = 0; i < n; i += 1) {
    for (long long j = 0; j < m; j += 1) {
      long long count = 0;
      if (arr[i][j] == 1) {
        count++;
      }
      if (arr[i][j + 1] == 1) {
        count++;
      }
      if (arr[i + 1][j] == 1) {
        count++;
      }
      if (arr[i + 1][j + 1] == 1) {
        count++;
      }
      if (count == 4) {
        ops += 1;
        out.push_back(i);
        out.push_back(j);
        out.push_back(i);
        out.push_back(j + 1);
        out.push_back(i + 1);
        out.push_back(j + 1);
        arr[i][j] = 0;
        arr[i][j + 1] = 0;
        arr[i + 1][j + 1] = 0;
        count = 1;
      }
      if (count == 2) {
        ops += 1;
        if (arr[i][j] == 1 && arr[i][j + 1] == 1) {
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j + 1);
          arr[i][j] = 0;
          arr[i][j + 1] = 0;
          arr[i + 1][j] = 1;
        } else if (arr[i + 1][j] == 1 && arr[i + 1][j + 1] == 1) {
          out.push_back(i);
          out.push_back(j);
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i + 1);
          out.push_back(j + 1);
          arr[i][j] = 1;
          arr[i + 1][j] = 0;
          arr[i + 1][j + 1] = 0;
        } else if (arr[i][j] == 1 && arr[i + 1][j] == 1) {
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j + 1);
          arr[i][j] = 0;
          arr[i + 1][j] = 0;
          arr[i][j + 1] = 1;
        } else if (arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1) {
          out.push_back(i);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j + 1);
          arr[i][j + 1] = 0;
          arr[i + 1][j + 1] = 0;
          arr[i][j] = 1;
        } else if (arr[i][j] == 1 && arr[i + 1][j + 1] == 1) {
          out.push_back(i);
          out.push_back(j);
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i + 1);
          out.push_back(j + 1);
          arr[i][j] = 0;
          arr[i + 1][j + 1] = 0;
          arr[i + 1][j] = 1;
        } else {
          out.push_back(i);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j);
          arr[i][j + 1] = 0;
          arr[i + 1][j] = 0;
          arr[i + 1][j + 1] = 1;
        }
        count = 1;
      }
      if (count == 3) {
        ops += 1;
        if (arr[i][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1) {
          out.push_back(i);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j + 1);
        } else if (arr[i + 1][j] == 1 && arr[i][j + 1] == 1 &&
                   arr[i + 1][j + 1] == 1) {
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j + 1);
        } else if (arr[i + 1][j] == 1 && arr[i][j] == 1 &&
                   arr[i + 1][j + 1] == 1) {
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j);
          out.push_back(i + 1);
          out.push_back(j + 1);
        } else {
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j + 1);
        }
      }
      if (count == 1) {
        ops += 3;
        if (arr[i][j] == 1) {
          out.push_back(i);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j);
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j + 1);
        } else if (arr[i][j + 1] == 1) {
          out.push_back(i);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j + 1);
          out.push_back(i);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j + 1);
        } else if (arr[i + 1][j] == 0) {
          out.push_back(i);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j + 1);
          out.push_back(i);
          out.push_back(j);
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i + 1);
          out.push_back(j + 1);
        } else {
          out.push_back(i);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j + 1);
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i);
          out.push_back(j);
          out.push_back(i + 1);
          out.push_back(j);
          out.push_back(i + 1);
          out.push_back(j + 1);
          out.push_back(i);
          out.push_back(j + 1);
        }
      }
      arr[i][j] = 0;
      arr[i + 1][j + 1] = 0;
      arr[i][j + 1] = 0;
      arr[i + 1][j] = 0;
    }
  }
  cout << ops << "\n";
  for (long long i = 0; i < out.size(); i += 6) {
    cout << out[i] + 1 << " " << out[i + 1] + 1 << " " << out[i + 2] + 1 << " "
         << out[i + 3] + 1 << " " << out[i + 4] + 1 << " " << out[i + 5] + 1
         << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
