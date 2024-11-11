#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
template <typename T, typename TT>
ostream &operator<<(ostream &s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream &operator<<(ostream &s, vector<T> t) {
  for (int(i) = 0; (i) < (((int)((t).size()))); ++(i)) s << t[i] << " ";
  return s;
}
namespace karkkainen {
inline bool leq(int a1, int a2, int b1, int b2) {
  return (a1 < b1 || (a1 == b1 && a2 <= b2));
}
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
  return (a1 < b1 || (a1 == b1 && leq(a2, a3, b2, b3)));
}
static void radixPass(int *a, int *b, int *r, int n, int K) {
  vector<int> c(K + 1, 0);
  for (int(i) = 0; (i) < (n); ++(i)) c[r[a[i]]]++;
  int sum = 0;
  for (int(i) = (0); (i) <= (K); ++i) {
    int t = c[i];
    c[i] = sum;
    sum += t;
  }
  for (int(i) = 0; (i) < (n); ++(i)) b[c[r[a[i]]]++] = a[i];
}
void suffixArray(int *s, int *SA, int n, int K) {
  int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
  int *s12 = new int[n02 + 3];
  s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
  int *SA12 = new int[n02 + 3];
  SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
  int *s0 = new int[n0];
  int *SA0 = new int[n0];
  for (int i = 0, j = 0; i < n + (n0 - n1); i++)
    if (i % 3 != 0) s12[j++] = i;
  radixPass(s12, SA12, s + 2, n02, K);
  radixPass(SA12, s12, s + 1, n02, K);
  radixPass(s12, SA12, s, n02, K);
  int name = 0, c0 = -1, c1 = -1, c2 = -1;
  for (int(i) = 0; (i) < (n02); ++(i)) {
    if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
      name++;
      c0 = s[SA12[i]];
      c1 = s[SA12[i] + 1];
      c2 = s[SA12[i] + 2];
    }
    if (SA12[i] % 3 == 1) {
      s12[SA12[i] / 3] = name;
    } else {
      s12[SA12[i] / 3 + n0] = name;
    }
  }
  if (name < n02) {
    suffixArray(s12, SA12, n02, name);
    for (int(i) = 0; (i) < (n02); ++(i)) s12[SA12[i]] = i + 1;
  } else {
    for (int(i) = 0; (i) < (n02); ++(i)) SA12[s12[i] - 1] = i;
  }
  for (int i = 0, j = 0; i < n02; ++i)
    if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
  radixPass(s0, SA0, s, n0, K);
  int p = 0, t = n0 - n1;
  for (int(k) = 0; (k) < (n); ++(k)) {
    int i = (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2);
    int j = SA0[p];
    if (SA12[t] < n0 ? leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3])
                     : leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j],
                           s[j + 1], s12[j / 3 + n0])) {
      SA[k] = i;
      t++;
      if (t == n02) {
        for (k++; p < n0; p++, k++) SA[k] = SA0[p];
      }
    } else {
      SA[k] = j;
      p++;
      if (p == n0) {
        for (k++; t < n02; t++, k++)
          SA[k] = (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2);
      }
    }
  }
  delete[] s12;
  delete[] SA12;
  delete[] SA0;
  delete[] s0;
}
};  // namespace karkkainen
struct SuffixArray {
  int *sa, *lcp, *revsa;
  SuffixArray(int *arr, bool with_lcp, int n) {
    if (n <= 1) {
      sa = new int[5];
      sa[0] = 0;
    } else {
      sa = new int[n + 3];
      arr[n] = arr[n + 1] = arr[n + 2] = 0;
      karkkainen::suffixArray(arr, sa, n, *max_element(arr, arr + n));
    }
    if (with_lcp) {
      lcp = new int[n + 3];
      vector<int> rank(n + 3);
      for (int(i) = 0; (i) < (n); ++(i)) rank[sa[i]] = i;
      for (int i = 0, k = 0; i < n; i++) {
        if (k > 0) k--;
        if (rank[i] == n - 1) {
          lcp[n - 1] = -1;
          k = 0;
          continue;
        }
        int j = sa[rank[i] + 1];
        while (arr[i + k] == arr[j + k]) k++;
        lcp[rank[i]] = k;
      }
    } else {
      lcp = NULL;
    }
    revsa = new int[n + 3];
    for (int(i) = 0; (i) < (n); ++(i)) revsa[sa[i]] = i;
  }
  ~SuffixArray() {
    delete[] sa;
    if (lcp != NULL) delete[] lcp;
  }
};
template <typename T, typename Aug>
struct AugTreap {
  struct Node {
    T v;
    int pr;
    Node *le, *ri;
    Aug al, ag;
  };
  Node *root;
  AugTreap() : root(0) {}
  inline static void recalc(Node *&n) {
    Aug left = n->le ? n->le->ag + n->al : n->al;
    n->ag = n->ri ? left + n->ri->ag : left;
  }
  inline void rotle(Node *&n) {
    Node *syn = n->le;
    n->le = syn->ri;
    syn->ri = n;
    n = syn;
    recalc(n->ri);
    recalc(n);
  }
  inline void rotri(Node *&n) {
    Node *syn = n->ri;
    n->ri = syn->le;
    syn->le = n;
    n = syn;
    recalc(n->le);
    recalc(n);
  }
  void insert_aux(Node *&n, const T &x, const Aug &aug) {
    if (!n) {
      n = new Node;
      n->v = x;
      n->pr = rand();
      n->le = n->ri = 0;
      n->al = n->ag = aug;
    } else if (x < n->v) {
      insert_aux(n->le, x, aug);
      if (n->pr > n->le->pr)
        rotle(n);
      else
        recalc(n);
    } else if (x > n->v) {
      insert_aux(n->ri, x, aug);
      if (n->pr > n->ri->pr)
        rotri(n);
      else
        recalc(n);
    } else {
      n->al = n->al + aug;
      recalc(n);
    }
  }
  void insert(const T &x, const Aug &aug) { insert_aux(root, x, aug); }
  Aug sumgeq_aux(const T &x, Node *n) {
    if (!n) return Aug();
    if (x > n->v) return sumgeq_aux(x, n->ri);
    if (x < n->v) {
      Aug left = sumgeq_aux(x, n->le) + n->al;
      return n->ri ? left + n->ri->ag : left;
    }
    return n->ri ? n->al + n->ri->ag : n->al;
  }
  Aug sumgeq(const T &x) { return sumgeq_aux(x, root); }
  Aug sumleq_aux(const T &x, Node *n) {
    if (!n) return Aug();
    if (x < n->v) return sumleq_aux(x, n->le);
    if (x > n->v) {
      Aug right = n->al + sumleq_aux(x, n->ri);
      return n->le ? n->le->ag + right : right;
    }
    return n->le ? n->le->ag + n->al : n->al;
  }
  Aug sumleq(const T &x) { return sumleq_aux(x, root); }
  Aug sumbetween_aux(const T &x, const T &y, Node *n) {
    if (!n) return Aug();
    if (y < n->v) return sumbetween_aux(x, y, n->le);
    if (x > n->v) return sumbetween_aux(x, y, n->ri);
    return sumgeq_aux(x, n->le) + n->al + sumleq_aux(y, n->ri);
  }
  Aug sumbetween(const T &x, const T &y) { return sumbetween_aux(x, y, root); }
};
struct IntMin {
  int x;
  IntMin(int y = 1001001001) : x(y) {}
  inline IntMin operator+(const IntMin &s) const { return IntMin(min(x, s.x)); }
  operator int() const { return x; }
};
int inp[200009];
int word[200009];
int ans[200009];
int newword[200009];
struct Todo {
  int from, to, maxIndex, whichQuery, multiplier, uniq;
};
bool operator<(const Todo &t, const Todo &r) {
  return t.maxIndex != r.maxIndex ? t.maxIndex < r.maxIndex : t.uniq < r.uniq;
}
int main() {
  int(n);
  scanf("%d", &(n));
  for (int(i) = 0; (i) < (n); ++(i)) {
    scanf("%d", inp + i);
  }
  for (int(i) = 0; (i) < (n - 1); ++(i)) {
    word[i] = inp[i + 1] - inp[i];
  }
  word[n - 1] = INT_MAX;
  for (int(i) = 0; (i) < (n - 1); ++(i)) {
    word[n + i] = -word[i];
  }
  int len = 2 * n - 1;
  map<int, int> mapa;
  int now = 1;
  for (int(i) = 0; (i) < (len); ++(i)) mapa[word[i]] = now++;
  for (int(i) = 0; (i) < (len); ++(i)) newword[i] = mapa[word[i]];
  SuffixArray sa(newword, 1, len);
  AugTreap<int, IntMin> lcpTreap;
  for (int(i) = 0; (i) < (len - 1); ++(i)) lcpTreap.insert(i, sa.lcp[i]);
  vector<Todo> todo;
  int uniquer = 0;
  int(queries);
  scanf("%d", &(queries));
  for (int(query) = 0; (query) < (queries); ++(query)) {
    int(l), (r);
    scanf("%d %d", &(l), &(r));
    --l;
    --r;
    if (l == r) {
      ans[query] = n - 1;
    } else {
      ans[query] = 0;
      int indexInSa = sa.revsa[n + l];
      int a = indexInSa, b = indexInSa;
      {
        int from = 0, to = indexInSa - 1;
        while (from <= to) {
          int mid = (from + to) / 2;
          int lcp = lcpTreap.sumbetween(mid, indexInSa - 1);
          if (lcp >= r - l) {
            a = mid;
            to = mid - 1;
          } else {
            from = mid + 1;
          }
        }
      }
      {
        int from = indexInSa + 1, to = len - 2;
        while (from <= to) {
          int mid = (from + to) / 2;
          int lcp = lcpTreap.sumbetween(indexInSa, mid - 1);
          if (lcp >= r - l) {
            b = mid;
            from = mid + 1;
          } else {
            to = mid - 1;
          }
        }
      }
      if (r + 1 <= n - 2) {
        todo.push_back((Todo){a, b, n - 2, query, 1, uniquer++});
        todo.push_back((Todo){a, b, r, query, -1, uniquer++});
      }
      if (0 <= l - (r - l)) {
        todo.push_back((Todo){a, b, l - (r - l), query, 1, uniquer++});
        todo.push_back((Todo){a, b, -1, query, -1, uniquer++});
      }
    }
  }
  sort(todo.begin(), todo.end());
  int nowToAddIndex = 0;
  AugTreap<int, int> cntTreap;
  for (typeof(todo.begin()) td = todo.begin(); td != todo.end(); td++) {
    for (; nowToAddIndex <= td->maxIndex; ++nowToAddIndex) {
      cntTreap.insert(sa.revsa[nowToAddIndex], 1);
    }
    int res = cntTreap.sumbetween(td->from, td->to);
    ans[td->whichQuery] += td->multiplier * res;
  }
  for (int(query) = 0; (query) < (queries); ++(query)) pisz(ans[query]);
}
