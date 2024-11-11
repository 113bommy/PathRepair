#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const string LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const long long LINF = (long long)9e18 + 7;
const long long P = 353251;
const long long P1 = 239017;
const long long P2 = 239017;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
int a[7], n;
vector<int> q[6];
int ans[100007];
int get(string s) {
  if (s == "S") return 0;
  if (s == "M") return 1;
  if (s == "L") return 2;
  if (s == "XL") return 3;
  if (s == "XXL") return 4;
  if (s == "XXXL") return 5;
}
void print(int k) {
  if (k == 0) cout << "S" << LN;
  if (k == 1) cout << "M" << LN;
  if (k == 2) cout << "L" << LN;
  if (k == 3) cout << "XL" << LN;
  if (k == 4) cout << "XXL" << LN;
  if (k == 5) cout << "XXXL" << LN;
}
const bool is_testing = 0;
int main() {
  srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
  if (is_testing) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  } else {
  }
  for (int i = 0; i < 6; i++) cin >> a[i];
  cin >> n;
  for (int i = 0; i < n; i++) {
    string now;
    cin >> now;
    string kek;
    for (int i = 0; i < now.size(); i++) {
      if (now[i] == ',') break;
      kek += now[i];
    }
    int ha = get(kek);
    if (now.size() == kek.size()) {
      a[ha]--;
      ans[i] = ha;
    } else {
      q[ha].push_back(i);
    }
  }
  for (int i = 4; i >= 0; i--) {
    for (int c : q[i]) {
      if (a[i + 1] <= 0) {
        ans[c] = i;
        a[i]--;
      } else {
        ans[c] = i + 1;
        a[i + 1]++;
      }
    }
  }
  for (int i = 0; i < 6; i++)
    if (a[i] < 0) {
      cout << "NO";
      exit(0);
    }
  cout << "YES" << LN;
  for (int i = 0; i < n; i++) print(ans[i]);
}
