#include <bits/stdc++.h>
using namespace std;
bool PIIfs(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}
bool PIIsf(const pair<int, int>& a, const pair<int, int>& b) {
  return a.second < b.second || (a.second == b.second && a.first < b.first);
}
bool PIIFS(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first > b.first || (a.first == b.first && a.second > b.second);
}
bool PIISF(const pair<int, int>& a, const pair<int, int>& b) {
  return a.second > b.second || (a.second == b.second && a.first > b.first);
}
bool PIIfS(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first < b.first || (a.first == b.first && a.second > b.second);
}
bool PIIsF(const pair<int, int>& a, const pair<int, int>& b) {
  return a.second < b.second || (a.second == b.second && a.first > b.first);
}
bool PIIFs(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first > b.first || (a.first == b.first && a.second < b.second);
}
bool PIISf(const pair<int, int>& a, const pair<int, int>& b) {
  return a.second > b.second || (a.second == b.second && a.first < b.first);
}
template <typename T>
inline T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <typename T>
inline T max(T a, T b, T c, T d) {
  return max(max(a, b, c), d);
}
template <typename T>
inline T max(T a, T b, T c, T d, T e) {
  return max(max(a, b, c, d), e);
}
template <typename T>
inline T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <typename T>
inline T min(T a, T b, T c, T d) {
  return min(min(a, b, c), d);
}
template <typename T>
inline T min(T a, T b, T c, T d, T e) {
  return min(min(a, b, c, d), e);
}
template <typename T>
inline istream& RD(T& x) {
  return cin >> x;
}
template <typename T, typename U>
inline istream& RD(T& a, U& b) {
  return cin >> a >> b;
}
template <typename T, typename U, typename V>
inline istream& RD(T& a, U& b, V& c) {
  return cin >> a >> b >> c;
}
template <typename T, typename U, typename V, typename W>
inline istream& RD(T& a, U& b, V& c, W& d) {
  return cin >> a >> b >> c >> d;
}
template <typename T, typename U, typename V, typename W, typename X>
inline istream& RD(T& a, U& b, V& c, W& d, X& e) {
  return cin >> a >> b >> c >> d >> e;
}
template <typename T>
void checkmin(T& a, const T& b) {
  if (b < a) a = b;
}
template <typename T>
void checkmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <typename T, typename V>
class IMarktype {
 protected:
  T v;

 public:
  virtual operator bool() = 0;
  virtual void clear() = 0;
  virtual IMarktype& merge(const IMarktype& parent) = 0;
  virtual V withValue(const V& oldValue) = 0;
  virtual ~IMarktype(){};
  const T get() const { return v; }
};
class LL_Mark : public IMarktype<long long, long long> {
 public:
  LL_Mark() { v = 0; }
  LL_Mark(long long i) { v = i; }
  operator bool() { return v; }
  void clear() { v = 0; }
  IMarktype<long long, long long>& merge(
      const IMarktype<long long, long long>& parent) {
    v += parent.get();
    return *this;
  }
  long long withValue(const long long& oldValue) { return v + oldValue; }
  static bool MERGABLE;
  static bool OK_WITH_BOSS_WHEN_SET_MARK;
};
bool LL_Mark::MERGABLE = true;
bool LL_Mark::OK_WITH_BOSS_WHEN_SET_MARK = true;
template <typename T, typename Marktype>
class SegmentTree {
  typedef T (*fnmerge)(const T& a, const T& b);
  typedef T (*fninit)(int l);

 public:
  struct Node {
    int l;
    int r;
    Marktype mark;
    T value;
    void setNode(int l_, int r_, const T& value_) {
      l = l_;
      r = r_;
      value = value_;
    }
  };
  Node* nedo;
  fnmerge merge;
  fninit init;
  SegmentTree(size_t N, fninit init_, fnmerge merge_)
      : query_head(indexof(0, N)) {
    nedo = new Node[2 * N - 1];
    merge = merge_;
    init = init_;
    build_aid(0, N);
  }
  ~SegmentTree() { delete[] nedo; }
  inline int indexof(int l, int r) {
    return (l - 1 + r) - ((r - l == 1) ? 0 : ((l + r) & 1));
  }
  T query(int l, int r) { return query_aid(query_head, l, r); }
  void update(int l, int r, Marktype mark) {
    update_aid(query_head, l, r, mark);
  }

 private:
  const int query_head;
  void build_aid(int l, int r) {
    if (l + 1 < r) {
      build_aid(l, (l + r) / 2);
      build_aid((l + r) / 2, r);
      nedo[indexof(l, r)].setNode(l, r,
                                  merge(nedo[indexof(l, (l + r) / 2)].value,
                                        nedo[indexof((l + r) / 2, r)].value));
    } else {
      nedo[indexof(l, r)].setNode(l, r, init(l));
    }
  }
  void pushDown(int which_node) {
    Marktype& mark = nedo[which_node].mark;
    if (mark) {
      int l = nedo[which_node].l;
      int r = nedo[which_node].r;
      if (r - l > 1) {
        if (Marktype::MERGABLE) {
          (nedo[indexof(l, (l + r) / 2)]).mark.merge(mark);
          (nedo[indexof((l + r) / 2, r)]).mark.merge(mark);
        } else {
          pushDown(indexof(l, (l + r) / 2));
          pushDown(indexof((l + r) / 2, r));
          (nedo[indexof(l, (l + r) / 2)]).mark = mark;
          (nedo[indexof((l + r) / 2, r)]).mark = mark;
        }
      }
      nedo[which_node].value = (nedo[which_node].value) + (r - l) * mark.get();
      nedo[which_node].mark.clear();
    }
  }
  T query_aid(int which_node, int l, int r) {
    pushDown(which_node);
    int lbound = nedo[which_node].l;
    int rbound = nedo[which_node].r;
    if (l <= lbound && rbound <= r) {
      return nedo[which_node].value;
    } else {
      T ans;
      int mid = (lbound + rbound) / 2;
      if (l < mid) {
        ans = query_aid(indexof(lbound, mid), l, r);
        if (r > mid) {
          ans = merge(ans, query_aid(indexof(mid, rbound), l, r));
        }
      } else {
        ans = query_aid(indexof(mid, rbound), l, r);
      }
      return ans;
    }
  }
  void update_aid(int which_node, int l, int r, const Marktype& mark) {
    int lbound = nedo[which_node].l;
    int rbound = nedo[which_node].r;
    if (l <= lbound && rbound <= r) {
      nedo[which_node].mark.merge(mark);
    } else {
      if (Marktype::OK_WITH_BOSS_WHEN_SET_MARK) {
      } else {
        pushDown(which_node);
      }
      int mid = (lbound + rbound) / 2;
      if (l < mid) {
        update_aid(indexof(lbound, mid), l, r, mark);
        if (r > mid) {
          update_aid(indexof(mid, rbound), l, r, mark);
        }
      } else {
        update_aid(indexof(mid, rbound), l, r, mark);
      }
      pushDown(indexof(lbound, mid));
      pushDown(indexof(mid, rbound));
      nedo[which_node].value = merge(nedo[indexof(lbound, mid)].value,
                                     nedo[indexof(mid, rbound)].value);
    }
  }
};
long long init_(int) { return 0; }
long long merge_(const long long& a, const long long& b) { return a + b; }
int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  map<int, int> mii;
  for (int i = 1; i <= (int)(n); ++i) {
    mii[i] = i;
  }
  SegmentTree<long long, LL_Mark> st(n + 1, init_, merge_);
  for (int temp_214710 = 0; temp_214710 < (int)(m); ++temp_214710) {
    int type;
    cin >> type;
    if (type == 1) {
      int b, e, c;
      cin >> b >> e >> c;
      if ((--mii.end())->first < b) {
        int old_val = mii.rbegin()->second;
        if (c == old_val) continue;
        if (e == n) {
          mii[b] = c;
          st.update(b, e + 1, abs(old_val - c));
        } else {
          mii[b] = c;
          mii[e + 1] = old_val;
          st.update(b, e + 1, abs(old_val - c));
        }
      } else {
        {
          map<int, int>::iterator bit = --mii.upper_bound(b);
          map<int, int>::iterator eit = --mii.upper_bound(e);
          int old_val = bit->second;
          if (bit == eit) {
            if (c == old_val) continue;
            if (e + 1 == mii.upper_bound(b)->second) {
              mii[b] = c;
              st.update(b, e + 1, abs(old_val - c));
            } else {
              mii[b] = c;
              mii[e + 1] = old_val;
              st.update(b, e + 1, abs(old_val - c));
            }
          } else {
            if (old_val == c) {
              bit++;
              b = bit->first;
            } else {
              st.update(b, ((++bit)->first), abs(old_val - c));
              mii[b] = c;
              bit = mii.find(b);
              bit++;
            }
            while (bit != eit) {
              int key_to_erase = bit->first;
              bit++;
              st.update(key_to_erase, bit->first, abs(mii[key_to_erase] - c));
              mii.erase(key_to_erase);
            }
            map<int, int>::iterator enext = mii.upper_bound(e);
            if (e == n || (enext != mii.end() && e + 1 == enext->first)) {
              st.update(bit->first, e + 1, abs(bit->second - c));
              mii.erase(bit);
            } else {
              int old___ = bit->second;
              st.update(bit->first, e + 1, abs(bit->second - c));
              mii.erase(bit);
              mii[e + 1] = old___;
            }
            map<int, int>::iterator ori_bit = mii.find(b);
            if (ori_bit != mii.begin() && ((--ori_bit)->second == c)) {
              mii.erase(b);
            }
          }
        }
      }
    } else {
      int b, e;
      cin >> b >> e;
      cout << st.query(b, e + 1) << '\n';
    }
  }
  return 0;
}
