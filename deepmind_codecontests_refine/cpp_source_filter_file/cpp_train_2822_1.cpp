#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long countArray[3 * N];
long long limit = 3 * N;
class Robot {
 public:
  long position;
  long radius;
  long iq;
  long left;
  long right;
  Robot() {}
  Robot(long position, long radius, long iq)
      : position(position), radius(radius), iq(iq) {}
  bool operator==(const Robot &rhs) const {
    return position == rhs.position && radius == rhs.radius && iq == rhs.iq;
  }
  bool operator!=(const Robot &rhs) const { return !(rhs == *this); }
  bool operator<(const Robot &rhs) const { return iq < rhs.iq; }
  bool operator>(const Robot &rhs) const { return rhs < *this; }
  bool operator<=(const Robot &rhs) const { return !(rhs < *this); }
  bool operator>=(const Robot &rhs) const { return !(*this < rhs); }
};
bool cmpForRadius(Robot i, Robot j) { return i.radius < j.radius; }
bool cmpForIq(Robot i, Robot j) { return i.iq < j.iq; }
int lowbit(int x) { return x & (-x); }
long long cdq(vector<Robot> &robots, int begin, int end, int k) {
  if (begin == end) {
    return 0;
  }
  int mid = (begin + end) / 2;
  long long count = cdq(robots, begin, mid, k) + cdq(robots, mid + 1, end, k);
  int midPoint1 = mid + 1, midPoint2 = mid + 1;
  for (int i = begin; i <= mid; i++) {
    while (midPoint2 <= end && robots[midPoint2].iq <= robots[i].iq + k) {
      for (int j = robots[midPoint2].position; j < limit; j += lowbit(j)) {
        countArray[j]++;
      }
      midPoint2++;
    }
    while (midPoint1 < midPoint2 && robots[midPoint1].iq < robots[i].iq - k) {
      for (int j = robots[midPoint1].position; j < limit; j += lowbit(j)) {
        countArray[j]--;
      }
      midPoint1++;
    }
    for (int j = robots[i].right; j > 0; j -= lowbit(j)) {
      count += countArray[j];
    }
    for (int j = robots[i].left - 1; j > 0; j -= lowbit(j)) {
      count -= countArray[j];
    }
  }
  for (int i = midPoint1; i < midPoint2; i++) {
    for (int j = robots[i].position; j < limit; j += lowbit(j)) {
      countArray[j] = 0;
    }
  }
  inplace_merge(robots.begin() + begin, robots.begin() + mid + 1,
                robots.begin() + end + 1, cmpForIq);
  return count;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<Robot> robots;
  vector<long> distances;
  for (int i = 0; i < n; i++) {
    long position, radius, iq;
    cin >> position >> radius >> iq;
    robots.push_back(Robot(position, radius, iq));
    distances.push_back(position);
    distances.push_back(position - radius);
    distances.push_back(position + radius);
  }
  sort(distances.begin(), distances.end());
  unique(distances.begin(), distances.end());
  for (int i = 0; i < n; i++) {
    robots[i].left = lower_bound(distances.begin(), distances.end(),
                                 robots[i].position - robots[i].radius) -
                     distances.begin() + 1;
    robots[i].right = lower_bound(distances.begin(), distances.end(),
                                  robots[i].position + robots[i].radius) -
                      distances.begin() + 1;
    robots[i].position =
        lower_bound(distances.begin(), distances.end(), robots[i].position) -
        distances.begin() + 1;
  }
  sort(robots.begin(), robots.end(), cmpForRadius);
  long count = 0;
  count = cdq(robots, 0, n - 1, k);
  cout << count << endl;
  return 0;
}
