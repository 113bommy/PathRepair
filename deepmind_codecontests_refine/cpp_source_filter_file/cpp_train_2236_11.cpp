#include <bits/stdc++.h>
using namespace std;
template <class T>
class reservable_priority_queue
    : public std::priority_queue<T, vector<T>, greater<T>> {
 public:
  reservable_priority_queue(
      typename std::priority_queue<T>::size_type capacity = 0) {
    reserve(capacity);
  };
  void reserve(typename std::priority_queue<T>::size_type capacity) {
    this->c.reserve(capacity);
  }
  typename std::priority_queue<T>::size_type capacity() const {
    return this->c.capacity();
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  uint32_t n, k;
  uint64_t length, startTime;
  ostringstream out;
  scanf("%d %d", &n, &k);
  reservable_priority_queue<uint64_t> queue;
  queue.reserve(k);
  for (uint32_t i = 0; i < n; i++) {
    scanf("%d %d", &startTime, &length);
    uint64_t end = startTime + length;
    if (queue.size() >= k) {
      uint64_t top = queue.top();
      queue.pop();
      end = max(top, startTime) + length;
    }
    out << end << endl;
    queue.push(end);
  }
  cout << out.str();
  return 0;
}
