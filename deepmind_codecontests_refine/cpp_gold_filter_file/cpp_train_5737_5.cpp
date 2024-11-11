#include <bits/stdc++.h>
using namespace std;
struct Segment {
  int l, r;
};
int main() {
  int n;
  cin >> n;
  Segment segments[n];
  int max_left = INT_MIN;
  int second_max_left = INT_MIN;
  int min_right = INT_MAX;
  int second_min_right = INT_MAX;
  int l, r;
  for (int i = 0; i < n; i++) {
    cin >> l;
    cin >> r;
    segments[i].l = l;
    segments[i].r = r;
    if (l >= max_left) {
      second_max_left = max_left;
      max_left = l;
    } else if (l >= second_max_left) {
      second_max_left = l;
    }
    if (r <= min_right) {
      second_min_right = min_right;
      min_right = r;
    } else if (r <= second_min_right) {
      second_min_right = r;
    }
  }
  int result = 0;
  for (int i = 0; i < n; i++) {
    int max = max_left;
    int min = min_right;
    if (segments[i].l == max_left) {
      max = second_max_left;
    }
    if (segments[i].r == min_right) {
      min = second_min_right;
    }
    if (min - max >= result) {
      result = min - max;
    }
  }
  std::cout << result << '\n';
}
