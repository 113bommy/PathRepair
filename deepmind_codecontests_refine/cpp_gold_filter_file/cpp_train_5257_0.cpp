#include <bits/stdc++.h>
using namespace std;
int data[26][800005];
int lazy[26][800005];
void updateValue(int low, int high, int idx, int index, int val, int alph) {
  if (low == high) {
    data[alph][index] = val;
    return;
  }
  int mid = (high + low) / 2;
  if (idx <= mid) {
    updateValue(low, mid, idx, 2 * index + 1, val, alph);
  } else
    updateValue(mid + 1, high, idx, 2 * index + 2, val, alph);
  data[alph][index] = data[alph][2 * index + 1] + data[alph][2 * index + 2];
}
void updateRange(int l, int r, int low, int high, int index, int diff,
                 int alph) {
  if (l > r) return;
  if (lazy[alph][index] != -1) {
    data[alph][index] = (high - low + 1) * lazy[alph][index];
    if (low != high) {
      lazy[alph][2 * index + 1] = lazy[alph][index];
      lazy[alph][2 * index + 2] = lazy[alph][index];
    }
    lazy[alph][index] = -1;
  }
  if (high < l or low > r) return;
  if (low >= l and high <= r) {
    data[alph][index] = (high - low + 1) * diff;
    if (low != high) {
      lazy[alph][2 * index + 1] = diff;
      lazy[alph][2 * index + 2] = diff;
    }
    return;
  }
  int mid = (low + high) / 2;
  updateRange(l, r, low, mid, 2 * index + 1, diff, alph);
  updateRange(l, r, mid + 1, high, 2 * index + 2, diff, alph);
  data[alph][index] = data[alph][2 * index + 1] + data[alph][2 * index + 2];
}
int getQuery(int l, int r, int low, int high, int index, int alph) {
  if (lazy[alph][index] != -1) {
    data[alph][index] = (high - low + 1) * lazy[alph][index];
    if (low != high) {
      lazy[alph][2 * index + 1] = lazy[alph][index];
      lazy[alph][2 * index + 2] = lazy[alph][index];
    }
    lazy[alph][index] = -1;
  }
  if (high < l or low > r) {
    return 0;
  }
  if (low >= l and high <= r) {
    return data[alph][index];
  }
  int mid = (low + high) / 2;
  return getQuery(l, r, low, mid, 2 * index + 1, alph) +
         getQuery(l, r, mid + 1, high, 2 * index + 2, alph);
}
int main() {
  ios::sync_with_stdio(false);
  for (int(i) = 0; (i) < (26); (i)++) {
    for (int(j) = 0; (j) < (800005); (j)++) {
      data[i][j] = 0;
      lazy[i][j] = -1;
    }
  }
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  for (int(i) = 0; (i) < (n); (i)++) {
    updateValue(0, n - 1, i, 0, 1, s[i] - 'a');
  }
  while (m--) {
    int temp1, temp2, c;
    cin >> temp1 >> temp2 >> c;
    int calc[26];
    for (int(i) = 0; (i) < (26); (i)++) {
      calc[i] = getQuery(temp1 - 1, temp2 - 1, 0, n - 1, 0, i);
    }
    if (c == 1) {
      int st = temp1 - 1;
      int en = st + calc[0] - 1;
      for (int(i) = 0; (i) < (26); (i)++) {
        updateRange(st, en, 0, n - 1, 0, 1, i);
        updateRange(temp1 - 1, st - 1, 0, n - 1, 0, 0, i);
        updateRange(en + 1, temp2 - 1, 0, n - 1, 0, 0, i);
        if (i != 25) {
          st = en + 1;
          en = st + calc[i + 1] - 1;
        }
      }
    } else {
      int st = temp1 - 1;
      int en = st + calc[25] - 1;
      for (int i = 25; i >= 0; i--) {
        updateRange(st, en, 0, n - 1, 0, 1, i);
        updateRange(temp1 - 1, st - 1, 0, n - 1, 0, 0, i);
        updateRange(en + 1, temp2 - 1, 0, n - 1, 0, 0, i);
        if (i != 0) {
          st = en + 1;
          en = st + calc[i - 1] - 1;
        }
      }
    }
  }
  for (int(i) = 0; (i) < (n); (i)++) {
    for (int(j) = 0; (j) < (26); (j)++) {
      if (getQuery(i, i, 0, n - 1, 0, j) == 1) {
        char ch = 'a' + j;
        cout << ch;
        break;
      }
    }
  }
  cout << endl;
  return 0;
}
