#include <bits/stdc++.h>
using namespace std;
void filein() { freopen("input.txt", "r", stdin); }
void fileout() { freopen("output.txt", "w", stdout); }
long long n, m, k;
int main() {
  long long n;
  cin >> n;
  if (n < 4) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  if (n % 4 == 0) {
    cout << "4 * 3 = 12\n2 * 12 = 24\n24 * 1 = 24\n";
    if (n == 4) return 0;
    vector<int> v;
    for (int i = 5; i <= n; i += 2) {
      if (i % 4 == 1) {
        cout << i << " - " << i + 1 << " = " << -1 << endl;
        v.push_back(-1);
      } else {
        cout << i + 1 << " - " << i << " = " << 1 << endl;
        v.push_back(1);
      }
    }
    for (int i = 0; i < v.size(); i += 2) {
      cout << "1 + -1 = 0\n24 + 0 = 24\n";
    }
    return 0;
  } else if (n % 4 == 2) {
    cout << "4 * 5 = 20\n6 - 3 = 3\n2 - 1 = 1\n20 + 3 = 23\n23 + 1 = 24\n";
    if (n == 6) return 0;
    vector<int> v;
    for (int i = 7; i <= n; i += 2) {
      if (i % 4 == 1) {
        cout << i << " - " << i + 1 << " = " << -1 << endl;
        v.push_back(-1);
      } else {
        cout << i + 1 << " - " << i << " = " << 1 << endl;
        v.push_back(1);
      }
    }
    for (int i = 0; i < v.size(); i += 2) {
      cout << "1 + -1 = 0\n24 + 0 = 24\n";
    }
    return 0;
  } else if (n % 4 == 1) {
    cout << "4 * 5 = 20\n20 + 3 = 23\n2 - 1 = 1\n23 + 1 = 24\n";
    vector<int> v;
    for (int i = 6; i <= n; i += 2) {
      if (i % 4 == 2) {
        cout << i << " - " << i + 1 << " = " << -1 << endl;
        v.push_back(-1);
      } else {
        cout << i + 1 << " - " << i << " = " << 1 << endl;
        v.push_back(1);
      }
    }
    for (int i = 0; i < v.size(); i += 2) {
      cout << "1 + -1 = 0\n24 + 0 = 24\n";
    }
    return 0;
  }
  cout << "4 * 6 = 24\n7 - 5 = 2\n3 - 1 = 2\n2 * 0 = 0\n0 * 2 = 0\n24 + 0 = "
          "24\n";
  vector<int> v;
  for (int i = 8; i <= n; i += 2) {
    if (i % 4 == 0) {
      cout << i << " - " << i + 1 << " = " << -1 << endl;
      v.push_back(-1);
    } else {
      cout << i + 1 << " - " << i << " = " << 1 << endl;
      v.push_back(1);
    }
  }
  for (int i = 0; i < v.size(); i += 2) {
    cout << "1 + -1 = 0\n24 + 0 = 24\n";
  }
}
