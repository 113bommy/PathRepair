#include <bits/stdc++.h>
using namespace std;
const long long INF = 1ll << 32;
vector<long long int> x;
vector<long long int> y;
vector<long long int> z[100110];
vector<long long int> z1[100110];
vector<long long int> vec;
vector<char> arr[200];
vector<pair<bool, bool> > v(1111);
map<long long int, long long int> mp;
string str[110], str2, s1;
set<long long int> s, s2;
long long int i, j, k, n, m, c, t, p, q, a, b, max2, max1, ans;
double f = 0, g = 0, h = 0;
char ch;
bool tf = true;
long long int vis[1001000] = {0};
stack<long long int> st, st1;
queue<long long int> qu;
list<long long int> l;
long long int fact(long long int n) {
  long long int res = 1;
  for (long long int i = 2; i <= n; i++) res = res * i;
  return res;
}
long long int nCr(long long int n, long long int r) {
  return fact(n) / (fact(r) * fact(n - r));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (i = 0; i < n; i++) {
      cin >> str[i];
    }
    long long int arr[101][110][7] = {0};
    for (i = 0; i < n - 1; i++) {
      for (j = 0; j < m - 1; j++) {
        k = 0;
        if (str[i][j] == '1') arr[i][j][0] = 1;
        if (str[i][j + 1] == '1') arr[i][j][1] = 1;
        if (str[i + 1][j] == '1') arr[i][j][2] = 1;
        if (str[i + 1][j + 1] == '1') arr[i][j][3] = 1;
        if (arr[i][j][0] || arr[i][j][1] || arr[i][j][2] || arr[i][j][3]) {
          x.push_back(i);
          y.push_back(j);
        }
        k = arr[i][j][0] + arr[i][j][1] + arr[i][j][2] + arr[i][j][3];
        if (k == 1)
          ans += 3;
        else if (k == 2)
          ans += 2;
        else if (k == 4)
          ans += 4;
        else if (k == 3)
          ans += 1;
        arr[i][j][4] = k;
        str[i][j] = str[i][j + 1] = str[i + 1][j] = str[i + 1][j + 1] = '0';
      }
    }
    cout << ans << "\n";
    m = 0;
    for (auto it : x) {
      i = it;
      j = y[m];
      m++;
      if (arr[i][j][4] == 3) {
        if (arr[i][j][0] == 0) {
          cout << i + 1 << " " << j + 2 << " " << i + 2 << " " << j + 1 << " "
               << i + 2 << " " << j + 2 << "\n";
        }
        if (arr[i][j][2] == 0) {
          cout << i + 1 << " " << j + 2 << " " << i + 2 << " " << j + 1 << " "
               << i + 2 << " " << j + 2 << "\n";
        }
        if (arr[i][j][1] == 0) {
          cout << i + 1 << " " << j + 2 << " " << i + 2 << " " << j + 1 << " "
               << i + 2 << " " << j + 2 << "\n";
        }
        if (arr[i][j][3] == 0) {
          cout << i + 1 << " " << j + 2 << " " << i + 2 << " " << j + 1 << " "
               << i + 2 << " " << j + 2 << "\n";
        }
      } else if (arr[i][j][4] == 2) {
        if (arr[i][j][0] == 0 && arr[i][j][1] == 0) {
          cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << " "
               << i + 2 << " " << j + 2 << "\n";
          cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << " "
               << i + 2 << " " << j + 1 << "\n";
        } else if (arr[i][j][0] == 0 && arr[i][j][3] == 0) {
          cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 2 << " "
               << i + 1 << " " << j + 2 << "\n";
          cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 2 << " "
               << i + 2 << " " << j + 1 << "\n";
        } else if (arr[i][j][0] == 0 && arr[i][j][2] == 0) {
          cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << " "
               << i + 1 << " " << j + 2 << "\n";
          cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << " "
               << i + 2 << " " << j + 2 << "\n";
        } else if (arr[i][j][1] == 0 && arr[i][j][2] == 0) {
          cout << i + 1 << " " << j + 2 << " " << i + 2 << " " << j + 1 << " "
               << i + 1 << " " << j + 1 << "\n";
          cout << i + 1 << " " << j + 2 << " " << i + 2 << " " << j + 1 << " "
               << i + 2 << " " << j + 2 << "\n";
        } else if (arr[i][j][1] == 0 && arr[i][j][3] == 0) {
          cout << i + 1 << " " << j + 2 << " " << i + 2 << " " << j + 2 << " "
               << i + 1 << " " << j + 1 << "\n";
          cout << i + 1 << " " << j + 2 << " " << i + 2 << " " << j + 2 << " "
               << i + 2 << " " << j + 1 << "\n";
        } else if (arr[i][j][2] == 0 && arr[i][j][3] == 0) {
          cout << i + 2 << " " << j + 1 << " " << i + 2 << " " << j + 2 << " "
               << i + 1 << " " << j + 1 << "\n";
          cout << i + 2 << " " << j + 1 << " " << i + 2 << " " << j + 2 << " "
               << i + 1 << " " << j + 2 << "\n";
        }
      } else if (arr[i][j][4] == 1) {
        if (arr[i][j][0] == 1) {
          cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << " "
               << i + 2 << " " << j + 1 << "\n";
          cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << " "
               << i + 2 << " " << j + 2 << "\n";
          cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << " "
               << i + 2 << " " << j + 2 << "\n";
        }
        if (arr[i][j][1] == 1) {
          cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << " "
               << i + 2 << " " << j + 2 << "\n";
          cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << " "
               << i + 2 << " " << j + 1 << "\n";
          cout << i + 1 << " " << j + 2 << " " << i + 2 << " " << j + 1 << " "
               << i + 2 << " " << j + 2 << "\n";
        }
        if (arr[i][j][3] == 1) {
          cout << i + 1 << " " << j + 2 << " " << i + 2 << " " << j + 2 << " "
               << i + 2 << " " << j + 1 << "\n";
          cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << " "
               << i + 2 << " " << j + 2 << "\n";
          cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << " "
               << i + 2 << " " << j + 2 << "\n";
        }
        if (arr[i][j][2] == 1) {
          cout << i + 1 << " " << j + 2 << " " << i + 2 << " " << j + 2 << " "
               << i + 2 << " " << j + 1 << "\n";
          cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << " "
               << i + 2 << " " << j + 1 << "\n";
          cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << " "
               << i + 2 << " " << j + 2 << "\n";
        }
      } else if (arr[i][j][4] == 4) {
        cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << " "
             << i + 2 << " " << j + 1 << "\n";
        cout << i + 1 << " " << j + 2 << " " << i + 2 << " " << j + 1 << " "
             << i + 2 << " " << j + 2 << "\n";
        cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << " "
             << i + 2 << " " << j + 2 << "\n";
        cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << " "
             << i + 2 << " " << j + 2 << "\n";
      }
    }
    x.clear();
    y.clear();
    ans = m = k = 0;
  }
}
