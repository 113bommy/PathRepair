#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
ostream &operator<<(ostream &out, pair<T, T1> obj) {
  out << "(" << obj.first << ", " << obj.second << ")";
  return out;
}
template <typename T, typename T1>
ostream &operator<<(ostream &out, map<T, T1> cont) {
  typename map<T, T1>::const_iterator itr = cont.begin();
  typename map<T, T1>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) {
    out << *itr << " ";
  }
  out << endl;
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, set<T> cont) {
  typename set<T>::const_iterator itr = cont.begin();
  typename set<T>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) {
    out << *itr << " ";
  }
  out << endl;
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, multiset<T> cont) {
  typename multiset<T>::const_iterator itr = cont.begin();
  typename multiset<T>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) {
    out << *itr << " ";
  }
  out << endl;
  return out;
}
template <typename T,
          template <typename ELEM, typename ALLOC = allocator<ELEM>> class CONT>
ostream &operator<<(ostream &out, CONT<T> cont) {
  typename CONT<T>::const_iterator itr = cont.begin();
  typename CONT<T>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) {
    out << *itr << " ";
  }
  out << endl;
  return out;
}
template <typename T, unsigned int N, typename CTy, typename CTr>
typename enable_if<!is_same<T, char>::value, basic_ostream<CTy, CTr> &>::type
operator<<(basic_ostream<CTy, CTr> &out, const T (&arr)[N]) {
  for (auto i = 0; i < N; ++i) {
    out << arr[i] << " ";
  }
  out << endl;
  return out;
}
template <typename T>
T GCD(T a, T b) {
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
T LCM(T a, T b) {
  return (a * b) / gcd(a, b);
}
template <typename T>
T fastExpPow(T base, T exp, T mod) {
  T res = 1;
  while (exp) {
    if (exp & 1) {
      res *= base;
      res %= mod;
    }
    exp >>= 1;
    base *= base;
    base %= mod;
  }
  return res % mod;
}
int N, K;
int numbers[300010], counts[1000000 + 10];
vector<int> possible;
int main() {
  scanf("%d%d", &N, &K);
  for (auto i = 0; i < N; ++i) {
    scanf("%d", numbers + i);
    ++counts[max(0, numbers[i] - K)];
    --counts[numbers[i] + 1];
  }
  sort(numbers, numbers + N);
  for (auto i = 1; i <= 1000000; ++i) {
    counts[i] += counts[i - 1];
  }
  for (auto num = 1; num <= numbers[0]; ++num) {
    if (numbers[0] % num <= K) {
      possible.push_back(num);
    }
  }
  reverse(possible.begin(), possible.end());
  for (auto num : possible) {
    int temp = num, cnt = 0;
    while (temp < 1000000) {
      cnt += counts[temp];
      temp += num;
    }
    if (cnt >= N) {
      printf("%d\n", num);
      return 0;
    }
  }
  return 0;
}
