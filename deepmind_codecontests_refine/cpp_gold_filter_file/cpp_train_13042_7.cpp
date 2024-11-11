#include <bits/stdc++.h>
using namespace std;
unsigned long long min(unsigned long long x, unsigned long long y) {
  if (x < y) return x;
  return y;
}
unsigned long long max(unsigned long long x, unsigned long long y) {
  if (x < y) return y;
  return x;
}
long long min(long long x, long long y) {
  if (x < y) return x;
  return y;
}
long long max(long long x, long long y) {
  if (x < y) return y;
  return x;
}
double min(double x, double y) {
  if (x < y) return x;
  return y;
}
double max(double x, double y) {
  if (x < y) return y;
  return x;
}
unsigned long long gcd(unsigned long long x, unsigned long long y) {
  if (!x) return y;
  if (!y) return x;
  if (x > y) swap(x, y);
  return gcd(x, y % x);
}
unsigned long long inv(unsigned long long a, unsigned long long c) {
  if (a == 1) {
    return 1;
  }
  return ((c - (c / a)) * inv(c % a, c)) % c;
}
int bsl(int a[], int n, int val) {
  int l = 0, r = n - 1;
  while (l < r - 1) {
    int mid = l + (r - l) / 2;
    if (a[mid] < val) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if (a[r] < val) return r;
  if (a[l] < val) return l;
  return l - 1;
}
int bsr(int a[], int n, int val) {
  int l = 0, r = n - 1;
  while (l < r - 1) {
    int mid = l + (r - l) / 2;
    if (a[mid] > val) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (a[l] > val) return l;
  if (a[r] > val) return r;
  return r + 1;
}
void printc(vector<pair<int, int> > move) {
  int i1 = move[0].first, j1 = move[0].second, i2 = move[1].first,
      j2 = move[1].second, i3 = move[2].first, j3 = move[2].second;
  cout << (i1) << " " << (j1) << " " << (i2) << " " << (j2) << " " << (i3)
       << " " << (j3) << "\n";
}
void flip(string s[], int i, int j) {
  if (s[i][j] == '0')
    s[i][j] = '1';
  else
    s[i][j] = '0';
}
void f(int a[2][2], vector<vector<pair<int, int> > > &moves, int n, int m) {
  for (int i = 0; i < 16; ++i) {
    int b[2][2] = {0};
    for (int j = 0; j < 4; ++j) {
      if (((i >> j) & 1) == 0) continue;
      int row = j / 2, col = j % 2;
      b[row][col] ^= 1;
      if (row < 1) b[row + 1][col] ^= 1;
      if (col < 1) b[row][col + 1] ^= 1;
      if (row > 0) b[row - 1][col] ^= 1;
      if (col > 0) b[row][col - 1] ^= 1;
    }
    bool ok = 1;
    for (int k = 0; k < 2; ++k) {
      for (int l = 0; l < 2; ++l) {
        if (a[k][l] != b[k][l]) ok = 0;
      }
    }
    if (ok) {
      for (int j = 0; j < 4; ++j) {
        if (((i >> j) & 1) == 0) continue;
        int row = j / 2, col = j % 2;
        vector<pair<int, int> > move;
        move.push_back(make_pair(row + n - 1, col + m - 1));
        if (row < 1) move.push_back(make_pair(row + 1 + n - 1, col + m - 1));
        if (col < 1) move.push_back(make_pair(row + n - 1, col + 1 + m - 1));
        if (row > 0) move.push_back(make_pair(row - 1 + n - 1, col + m - 1));
        if (col > 0) move.push_back(make_pair(row + n - 1, col - 1 + m - 1));
        moves.push_back(move);
      }
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, cnt = 0;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      for (char &c : s[i]) {
        cnt += (c == '1');
      }
    }
    vector<vector<pair<int, int> > > moves;
    for (int i = 0; i < n - 2; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '0') continue;
        vector<pair<int, int> > move;
        if (j < m - 1) {
          flip(s, i, j);
          move.push_back(make_pair(i + 1, j + 1));
          flip(s, i + 1, j);
          move.push_back(make_pair(i + 2, j + 1));
          flip(s, i + 1, j + 1);
          move.push_back(make_pair(i + 2, j + 2));
          moves.push_back(move);
        } else {
          flip(s, i, j);
          move.push_back(make_pair(i + 1, j + 1));
          flip(s, i + 1, j);
          move.push_back(make_pair(i + 2, j + 1));
          flip(s, i + 1, j - 1);
          move.push_back(make_pair(i + 2, j));
          moves.push_back(move);
        }
      }
    }
    for (int j = 0; j < m - 2; ++j) {
      vector<pair<int, int> > move;
      if (s[n - 2][j] == '1') {
        flip(s, n - 2, j);
        move.push_back(make_pair(n - 1, j + 1));
        flip(s, n - 2, j + 1);
        move.push_back(make_pair(n - 1, j + 2));
        flip(s, n - 1, j + 1);
        move.push_back(make_pair(n, j + 2));
        moves.push_back(move);
      }
      move.clear();
      if (s[n - 1][j] == '1') {
        flip(s, n - 1, j);
        move.push_back(make_pair(n, j + 1));
        flip(s, n - 1, j + 1);
        move.push_back(make_pair(n, j + 2));
        flip(s, n - 2, j + 1);
        move.push_back(make_pair(n - 1, j + 2));
        moves.push_back(move);
      }
    }
    int left[2][2] = {0};
    for (int i = n - 2; i < n; ++i) {
      for (int j = m - 2; j < m; ++j) {
        left[i - n + 2][j - m + 2] = (s[i][j] == '1');
      }
    }
    f(left, moves, n, m);
    cout << moves.size() << "\n";
    for (int i = 0; i < moves.size(); ++i) {
      printc(moves[i]);
    }
  }
  return 0;
}
