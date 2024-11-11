#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int mod = 2000000007;
const int inf = 50000000;
const int maxn = 100010;
int n, k, A[maxn], notSet[maxn];
vector<int> v[maxn], temp;
string str;
int push(int l, int r, int sz) {
  if (1LL * r - l - 1 < sz) {
    return 0;
  }
  temp.clear();
  if (l < 0 && r < 0) {
    for (int i = 0; i < sz; i++) {
      temp.push_back(r - i - 1);
    }
    reverse(temp.begin(), temp.end());
  } else if (l > 0 && r > 0) {
    for (int i = 0; i < sz; i++) {
      temp.push_back(l + i + 1);
    }
  } else {
    int c = 0;
    long long sum = 1LL << 50;
    for (int i = 0; i < sz; i++) {
      if (-l - 1 < i) {
        break;
      }
      if (r - 1 < sz - i - 1) {
        continue;
      }
      long long second =
          (1LL * (i - 1) * i) / 2 + (1LL * (sz - i - 1) * (sz - i)) / 2;
      if (second < sum) {
        sum = second;
        c = -i;
      }
    }
    for (int i = 0; i < sz; i++) {
      temp.push_back(c);
      c += 1;
    }
  }
  return 1;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (str[0] == '?') {
      notSet[i] = 1;
      A[i] = mod;
    } else {
      A[i] = stoi(str);
    }
    v[i % k].push_back(A[i]);
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < v[i].size();) {
      if (v[i][j] == mod) {
        int p = j;
        while (p < v[i].size()) {
          if (v[i][p] != mod) {
            break;
          }
          p += 1;
        }
        int lft = (j == 0) ? -mod : v[i][j - 1];
        int rgt = (p == v[j].size()) ? mod : v[i][p];
        if (!push(lft, rgt, p - j)) {
          printf("Incorrect sequence\n");
          return 0;
        } else {
          int c = 0;
          while (j < p) {
            A[j * k + i] = v[i][j] = temp[c];
            j += 1;
            c += 1;
          }
        }
      } else {
        if (j > 0 && v[i][j] <= v[i][j - 1]) {
          printf("Incorrect sequence\n");
          return 0;
        }
        j += 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}
