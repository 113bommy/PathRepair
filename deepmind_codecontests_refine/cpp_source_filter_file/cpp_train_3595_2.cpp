#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
ostream &operator<<(ostream &out, pair<T, T1> obj) {
  out << "(" << obj.first << "," << obj.second << ")";
  return out;
}
template <typename T, typename T1>
ostream &operator<<(ostream &out, map<T, T1> cont) {
  typename map<T, T1>::const_iterator itr = cont.begin();
  typename map<T, T1>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) out << *itr << " ";
  out << endl;
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, set<T> cont) {
  typename set<T>::const_iterator itr = cont.begin();
  typename set<T>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) out << *itr << " ";
  out << endl;
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, multiset<T> cont) {
  typename multiset<T>::const_iterator itr = cont.begin();
  typename multiset<T>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) out << *itr << " ";
  out << endl;
  return out;
}
template <typename T,
          template <typename ELEM, typename ALLOC = allocator<ELEM>> class CONT>
ostream &operator<<(ostream &out, CONT<T> cont) {
  typename CONT<T>::const_iterator itr = cont.begin();
  typename CONT<T>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) out << *itr << " ";
  out << endl;
  return out;
}
template <typename T, unsigned int N, typename CTy, typename CTr>
typename enable_if<!is_same<T, char>::value, basic_ostream<CTy, CTr> &>::type
operator<<(basic_ostream<CTy, CTr> &out, const T (&arr)[N]) {
  for (auto i = 0; i < N; ++i) out << arr[i] << " ";
  out << endl;
  return out;
}
template <typename T>
T gcd(T a, T b) {
  T min_v = min(a, b);
  T max_v = max(a, b);
  while (min_v) {
    T temp = max_v % min_v;
    max_v = min_v;
    min_v = temp;
  }
  return max_v;
}
template <typename T>
T lcm(T a, T b) {
  return (a * b) / gcd(a, b);
}
template <typename T>
T fast_exp_pow(T base, T exp, T mod) {
  long long res = 1;
  while (exp) {
    if (exp & 1) {
      res *= base;
      res %= mod;
    }
    exp >>= 1;
    base *= base;
    base %= mod;
  }
  return res;
}
int N, M, max_len;
int dp_pos[10010];
long long hashs;
string text, rev_text, wrd;
vector<string> words;
map<long long, int> rev_hashes;
long long get_hash(string str) {
  long long ret = 0;
  for (auto lt : str) ret = (ret * 257 + lt - 'a') % 1000000007;
  return ret;
}
int main() {
  scanf("%d", &N);
  cin >> text;
  scanf("%d", &M);
  for (auto i = 0; i < M; ++i) {
    cin >> wrd;
    words.push_back(wrd);
    max_len = max(max_len, (int)wrd.size());
    reverse(wrd.begin(), wrd.end());
    for (auto &lt : wrd) lt = tolower(lt);
    rev_hashes[get_hash(wrd)] = i;
  }
  rev_text = text;
  reverse(rev_text.begin(), rev_text.end());
  memset(dp_pos, -1, sizeof(dp_pos));
  dp_pos[0] = 100001;
  for (auto i = 1; i <= N; ++i) {
    hashs = 0;
    for (auto j = 1; j <= min(i, max_len); ++j) {
      hashs = (hashs * 257 + rev_text[i - j] - 'a') % 1000000007;
      if (dp_pos[i - j] != -1 && rev_hashes.count(hashs))
        dp_pos[i] = rev_hashes[hashs];
    }
  }
  int pos = N;
  while (pos > 0) {
    int pos_1 = dp_pos[pos];
    cout << words[pos_1] << " ";
    pos -= words[pos_1].size();
  }
  return 0;
}
