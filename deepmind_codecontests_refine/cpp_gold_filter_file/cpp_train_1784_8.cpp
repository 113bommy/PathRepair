#include <bits/stdc++.h>
using namespace std;
const int N = 555;
string grid[N], grid2[N], grid3[N];
bool sw;
int n, m;
int getDiff() {
  int ans = 0;
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (m); j++) {
      ans += grid[i][j] != grid2[i][j];
    }
  }
  return ans;
}
void gen(char c, char d, char e, char f, bool col) {
  for (int i = (1); i <= (n); i++) {
    grid2[i] = string(m + 2, ' ');
  }
  if (col) {
    for (int i = (1); i <= (n); i++) {
      if (i & 1) {
        int d1 = 0, d2 = 0;
        for (int j = (1); j <= (m); j++) {
          d1 += grid[i][j] != (j & 1 ? c : d);
          d2 += grid[i][j] != (j & 1 ? d : c);
        }
        for (int j = (1); j <= (m); j++) {
          grid2[i][j] = (j & 1) ^ (d1 > d2) ? c : d;
        }
      } else {
        int d1 = 0, d2 = 0;
        for (int j = (1); j <= (m); j++) {
          d1 += grid[i][j] != (j & 1 ? e : f);
          d2 += grid[i][j] != (j & 1 ? f : e);
        }
        for (int j = (1); j <= (m); j++) {
          grid2[i][j] = (j & 1) ^ (d1 > d2) ? e : f;
        }
      }
    }
  } else {
    for (int j = (1); j <= (m); j++) {
      if (j & 1) {
        int d1 = 0, d2 = 0;
        for (int i = (1); i <= (n); i++) {
          d1 += grid[i][j] != (i & 1 ? c : d);
          d2 += grid[i][j] != (i & 1 ? d : c);
        }
        for (int i = (1); i <= (n); i++) {
          grid2[i][j] = (i & 1) ^ (d1 > d2) ? c : d;
        }
      } else {
        int d1 = 0, d2 = 0;
        for (int i = (1); i <= (n); i++) {
          d1 += grid[i][j] != (i & 1 ? e : f);
          d2 += grid[i][j] != (i & 1 ? f : e);
        }
        for (int i = (1); i <= (n); i++) {
          grid2[i][j] = (i & 1) ^ (d1 > d2) ? e : f;
        }
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  sw = n > m;
  for (int i = (1); i <= (sw ? m : n); i++) {
    grid[i] = string(sw ? n + 2 : m + 2, ' ');
  }
  for (int i = (1); i <= (n); i++) {
    string s;
    cin >> s;
    for (int j = (1); j <= (m); j++) {
      if (sw) {
        grid[j][i] = s[j - 1];
      } else {
        grid[i][j] = s[j - 1];
      }
    }
  }
  if (sw) swap(n, m);
  string al = "ACGT";
  set<char> st;
  for (int c = (0); c <= (3); c++) {
    st.insert(c);
  }
  int best = 1e9;
  for (int c = (0); c <= (3); c++) {
    st.erase(st.find(c));
    for (int d = (c + 1); d <= (3); d++) {
      st.erase(st.find(d));
      for (int col = (false); col <= (true); col++) {
        gen(al[c], al[d], al[*(st.begin())], al[*(st.rbegin())], col);
        int diff = getDiff();
        if (diff < best) {
          best = diff;
          copy(grid2 + 1, grid2 + n + 1, grid3 + 1);
        }
      }
      st.insert(d);
    }
    st.insert(c);
  }
  if (sw) {
    for (int i = (1); i <= (m); i++) {
      for (int j = (1); j <= (n); j++) {
        cout << grid3[j][i];
      }
      cout << endl;
    }
  } else {
    for (int i = (1); i <= (n); i++) {
      for (int j = (1); j <= (m); j++) {
        cout << grid3[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
