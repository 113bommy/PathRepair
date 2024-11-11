#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int INF = 0x3f3f3f3f;
const long long MOD = 1e9 + 7;
template <class T>
inline bool RD(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1, ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <class T>
inline void PT(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) PT(x / 10);
  putchar(x % 10 + '0');
}
const int N = 210;
const long long LIM = -(1LL << 60);
struct node {
  node *next[26];
  node *fail;
  int id;
  long long val;
} trie[N], *que[N], *root;
struct AC {
  int head, tail, L;
  node *createnode() {
    L++;
    trie[L].fail = NULL;
    memset(trie[L].next, 0, sizeof(trie[L].next));
    trie[L].val = 0;
    trie[L].id = L;
    return &trie[L];
  }
  void init() {
    head = tail = L = 0;
    root = createnode();
    root->fail = root;
  }
  void Insert(char str[], int val) {
    node *cur = root;
    for (int i = 0; str[i]; i++) {
      int val = str[i] - 'a';
      if (cur->next[val] == NULL) cur->next[val] = createnode();
      cur = cur->next[val];
    }
    cur->val += val;
  }
  void build() {
    que[head++] = root;
    while (head > tail) {
      node *cur = que[tail++];
      cur->val += cur->fail->val;
      for (int i = 0; i < 26; i++) {
        if (cur->next[i] != NULL) {
          if (cur == root)
            cur->next[i]->fail = root;
          else
            cur->next[i]->fail = cur->fail->next[i];
          que[head++] = cur->next[i];
        } else {
          if (cur == root)
            cur->next[i] = root;
          else
            cur->next[i] = cur->fail->next[i];
        }
      }
    }
  }
} A;
int val[N];
char str[N];
struct mat {
  long long a[N][N];
  mat() {
    for (int i = 1; i <= A.L; i++)
      for (int j = 1; j <= A.L; j++) a[i][j] = LIM;
  }
};
mat mul(mat a, mat b) {
  mat ans;
  for (int i = (1), i_end_ = (A.L + 1); i < i_end_; ++i)
    for (int j = (1), j_end_ = (A.L + 1); j < j_end_; ++j)
      for (int k = (1), k_end_ = (A.L + 1); k < k_end_; ++k)
        chkmax(ans.a[i][k], a.a[i][j] + b.a[j][k]);
  return ans;
}
void Print(mat m) {
  puts("****");
  long long tmp = -1;
  for (int i = 1; i <= A.L; i++, puts(""))
    for (int j = 1; j <= A.L; j++)
      printf("(%lld)", m.a[i][j] < -1000 ? tmp : m.a[i][j]);
  puts("");
}
mat quickmul(mat m, int K) {
  mat ans;
  for (int i = 1; i <= A.L; i++) ans.a[i][i] = 0;
  while (K) {
    if (K & 1) ans = mul(ans, m);
    m = mul(m, m);
    K >>= 1;
  }
  for (int i = 1; i <= K; i++) ans = mul(ans, m), Print(ans);
  return ans;
}
int main() {
  A.init();
  int n;
  long long m;
  cin >> n >> m;
  for (int i = (0), i_end_ = (n); i < i_end_; ++i) RD(val[i]);
  for (int i = (0), i_end_ = (n); i < i_end_; ++i) {
    scanf("%s", str);
    A.Insert(str, val[i]);
  }
  A.build();
  mat DFA;
  for (int i = 1; i <= A.L; i++) {
    for (int j = 0; j < 26; j++)
      DFA.a[i][trie[i].next[j]->id] = trie[i].next[j]->val;
  }
  mat res = quickmul(DFA, m);
  long long ans = LIM;
  for (int i = 1; i <= A.L; i++) chkmax(ans, res.a[1][i]);
  printf("%lld\n", ans);
}
