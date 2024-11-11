#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  if (a < b) return gcd(b, a);
  while (a > b) {
    a %= b;
  }
  return gcd(b, a);
}
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int INF = (1LL << 29);
using namespace std;
template <typename T>
string toString(T t) {
  stringstream ss;
  ss << t;
  return ss.str();
}
typedef struct Order {
  int i;
  long long h, a;
  Order() { ; }
  Order(int ii) : i(ii) { ; }
  bool operator<(const Order &o2) const {
    if (a != o2.a) return a < o2.a;
    return h > o2.h;
  }
} Order;
bool cmp1(const Order &o1, const Order &o2) {
  if (o1.h == o2.h) return o1.a < o2.a;
  return o1.h < o2.h;
}
int main() {
  int N, P, K;
  cin >> N >> P >> K;
  vector<Order> order(N);
  for (int i = 0; i < N; i++) {
    order[i] = Order(i);
    cin >> order[i].h >> order[i].a;
  }
  vector<Order> left;
  sort(order.begin(), order.end());
  vector<Order> right;
  sort(order.begin() + P - K, order.end(), cmp1);
  for (int k = 0; k < K; k++) {
    right.push_back(order[N - k - 1]);
  }
  sort(right.begin(), right.end());
  sort(order.begin(), order.end() - K);
  for (int k = N - K - 1; left.size() < P - K && k >= 0; k--) {
    Order last = right[0];
    if (order[k].a < last.a || (order[k].a == last.a && order[k].h > last.h))
      left.push_back(order[k]);
  }
  for (int i = 0; i < left.size(); i++) {
    cout << left[i].i + 1 << endl;
  }
  for (int j = 0; j < right.size(); j++) {
    cout << right[j].i + 1 << endl;
  }
  return 0;
}
