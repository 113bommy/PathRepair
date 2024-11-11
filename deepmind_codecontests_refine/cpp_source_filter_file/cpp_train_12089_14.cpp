#include <bits/stdc++.h>
using namespace std;
int n, q;
string second;
struct Suffix {
  int index;
  int thisRank;
  int nextRank;
};
bool comp(Suffix suf1, Suffix suf2) {
  if (suf1.thisRank != suf2.thisRank) return suf1.thisRank < suf2.thisRank;
  return suf1.nextRank < suf2.nextRank;
}
Suffix suffs[200005];
int indices[200005];
int sufArr[200005];
void suffArr(string str) {
  int strLen = str.length();
  for (int i = 0; i < strLen; i++) {
    suffs[i].index = i;
    suffs[i].thisRank = str[i] - 'a';
    if (i == strLen - 1) {
      suffs[i].nextRank = -1;
    } else {
      suffs[i].nextRank = str[i + 1] - 'a';
    }
  }
  sort(suffs, suffs + strLen, comp);
  for (int amt = 4; amt < 2 * strLen; amt *= 2) {
    int currRank = 0;
    int prevRank = suffs[0].thisRank;
    suffs[0].thisRank = 0;
    indices[suffs[0].index] = 0;
    for (int i = 1; i < strLen; i++) {
      if (suffs[i].thisRank != prevRank ||
          suffs[i].nextRank != suffs[i - 1].nextRank) {
        currRank++;
      }
      prevRank = suffs[i].thisRank;
      suffs[i].thisRank = currRank;
      indices[suffs[i].index] = i;
    }
    for (int i = 0; i < strLen; i++) {
      int otherInd = suffs[i].index + amt / 2;
      if (otherInd >= strLen) {
        suffs[i].nextRank = -1;
      } else {
        suffs[i].nextRank = suffs[indices[otherInd]].thisRank;
      }
    }
    sort(suffs, suffs + strLen, comp);
  }
  for (int i = 0; i < strLen; i++) {
    sufArr[i] = suffs[i].index;
  }
}
int lcp[200005];
int inv[200005];
void getLCP(string str) {
  int strLen = str.length();
  for (int i = 0; i < (signed)(strLen); i++) {
    inv[sufArr[i]] = i;
  }
  int k = 0;
  for (int i = 0; i < (signed)(strLen); i++) {
    if (inv[i] == strLen - 1) {
      k = 0;
      continue;
    }
    int j = sufArr[inv[i] + 1];
    while (i + k < strLen && j + k < strLen && str[i + k] == str[j + k]) k++;
    lcp[inv[i]] = k;
    if (k > 0) k--;
  }
}
int tree[200005 * 4];
void build(int node, int a, int b) {
  if (a == b) {
    tree[node] = lcp[a - 1];
    return;
  }
  build(node * 2, a, (a + b) / 2);
  build(node * 2 + 1, 1 + (a + b) / 2, b);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int query(int node, int a, int b, int i, int j) {
  if (i > j) swap(i, j);
  if (a > b || a > j || b < i) return 1000000000;
  if (a >= i && b <= j) return tree[node];
  int q1 = query(node * 2, a, (a + b) / 2, i, j);
  int q2 = query(node * 2 + 1, 1 + (a + b) / 2, b, i, j);
  return min(q1, q2);
}
vector<int> a, b;
map<int, long long> aah;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  cin >> second;
  suffArr(second);
  getLCP(second);
  build(1, 1, n);
  for (int _ = 0; _ < (signed)(q); _++) {
    int k, l;
    cin >> k >> l;
    for (int _ = 0; _ < (signed)(k); _++) {
      int x;
      cin >> x;
      a.push_back(inv[x - 1]);
    }
    for (int _ = 0; _ < (signed)(l); _++) {
      int x;
      cin >> x;
      b.push_back(inv[x - 1]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long sm = 0;
    long long cur = 0;
    int j = l - 1;
    for (int i = (k - 1); i >= 0; i--) {
      if (i != k - 1) {
        int val = query(1, 1, n, a[i] + 1, a[i + 1]);
        auto it = aah.upper_bound(val);
        for (; it != aah.end();) {
          cur = cur + val * (it->second) - (it->first) * (it->second);
          aah[val] += it->second;
          it = aah.erase(it);
        }
      }
      while (j > 0 && b[j] > a[i]) {
        int val = query(1, 1, n, a[i] + 1, b[j]);
        cur += val;
        aah[val] += 1;
        --j;
      }
      if (j >= 0 && b[j] == a[i]) {
        int loc = sufArr[a[i]];
        int ch = n - loc;
        sm += ch;
      }
      sm += cur;
    }
    aah.clear();
    j = k - 1;
    cur = 0;
    for (int i = (l - 1); i >= 0; i--) {
      if (i != l - 1) {
        int val = query(1, 1, n, b[i] + 1, b[i + 1]);
        auto it = aah.upper_bound(val);
        for (; it != aah.end();) {
          cur = cur + val * (it->second) - (it->first) * (it->second);
          aah[val] += it->second;
          it = aah.erase(it);
        }
      }
      while (j >= 0 && a[j] > b[i]) {
        int val = query(1, 1, n, b[i] + 1, a[j]);
        cur += val;
        aah[val] += 1;
        --j;
      }
      sm += cur;
    }
    cout << sm << "\n";
    aah.clear();
    a.clear();
    b.clear();
  }
  return 0;
}
