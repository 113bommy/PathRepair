#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, const string& delim = " ") {
  vector<string> res;
  string t;
  for (int i = 0; i != s.size(); i++) {
    if (delim.find(s[i]) != string::npos) {
      if (!t.empty()) {
        res.push_back(t);
        t = "";
      }
    } else {
      t += s[i];
    }
  }
  if (!t.empty()) {
    res.push_back(t);
  }
  return res;
}
vector<int> splitInt(const string& s, const string& delim = " ") {
  vector<string> tok = split(s, delim);
  vector<int> res;
  for (int i = 0; i != tok.size(); i++) res.push_back(atoi(tok[i].c_str()));
  return res;
}
template <typename T>
void print(T a) {
  cerr << a;
}
static void print(long long a) { cerr << a << "L"; }
static void print(string a) { cerr << '"' << a << '"'; }
template <typename T>
void print(vector<T> a) {
  cerr << "{";
  for (int i = 0; i != a.size(); i++) {
    if (i != 0) cerr << ", ";
    print(a[i]);
  }
  cerr << "}" << endl;
}
char s[505];
char s2[505];
int best[505][505];
int pal[505][505];
int cut[505][505];
string al[505][505];
int n;
int toPal(int L, int R) {
  if (L >= R) {
    return 0;
  }
  if (pal[L][R] == -1) {
    pal[L][R] = (s[L] != s[R]) + toPal(L + 1, R - 1);
  }
  return pal[L][R];
}
int calc(int idx, int k) {
  if (idx == n) {
    return 0;
  }
  if (best[idx][k] == -1) {
    int res = toPal(idx, n - 1);
    for (int i = (idx), _n = (n - 1); i <= _n; i++)
      if (k > 1) {
        int temp = toPal(idx, i) + calc(i + 1, k - 1);
        if (temp < res) {
          res = temp;
          cut[idx][k] = i;
        }
      }
    best[idx][k] = res;
  }
  return best[idx][k];
}
void printcut(int idx, int k) {
  if (idx >= n) return;
  int start = idx;
  int end = cut[idx][k];
  if (end == -1) end = n - 1;
  while (start <= end) {
    if (s[start] != s[end]) s[start] = s[end];
    start++;
    end--;
  }
  int R = cut[idx][k];
  if (R == -1) R = n - 1;
  char c = s[R + 1];
  s[R + 1] = 0;
  printf("%s", s + idx);
  s[R + 1] = c;
  if (cut[idx][k] == -1)
    puts("");
  else {
    printf("+");
    printcut(cut[idx][k] + 1, k - 1);
  }
}
int main() {
  int k;
  while (scanf("%s", s) != EOF) {
    memset(best, -1, sizeof(best));
    memset(pal, -1, sizeof(pal));
    memset(cut, -1, sizeof(cut));
    scanf("%d", &k);
    n = strlen(s);
    printf("%d\n", calc(0, k));
    printcut(0, k);
  }
  return 0;
}
