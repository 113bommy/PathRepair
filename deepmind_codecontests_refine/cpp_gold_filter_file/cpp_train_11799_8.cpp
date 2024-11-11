#include <bits/stdc++.h>
bool compare_int_pairs(const std::pair<int, int> &left,
                       const std::pair<int, int> &right) {
  return left.first < right.first;
}
int main(int argc, char **argv) {
  int n, t;
  std::cin >> n >> t;
  std::vector<std::pair<int, int> > inputs(n, std::pair<int, int>());
  for (int i = 0; i < n; ++i) {
    std::cin >> inputs[i].first >> inputs[i].second;
  }
  std::sort(inputs.begin(), inputs.end(), compare_int_pairs);
  int num_of_places = 2;
  for (int i = 0; i < n - 1; ++i) {
    double end_coordinate = inputs[i].first + inputs[i].second / 2.0;
    double start_coordinate = inputs[i + 1].first - inputs[i + 1].second / 2.0;
    double gap_width = start_coordinate - end_coordinate;
    if (gap_width > t) {
      num_of_places += 2;
    } else if (gap_width == t) {
      num_of_places += 1;
    }
  }
  std::cout << num_of_places << '\n';
  return 0;
}
