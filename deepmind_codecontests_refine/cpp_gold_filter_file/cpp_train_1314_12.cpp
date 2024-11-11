#include <bits/stdc++.h>
namespace {
using i64 = long long;
using ui64 = unsigned long long;
using ui32 = unsigned int;
}  // namespace
int main() {
  int N;
  std::cin >> N;
  std::vector<std::pair<char, int>> arr(N);
  for (auto& el : arr) {
    std::cin >> el.first >> el.second;
  }
  std::pair<char, int> digs[10];
  ui32 a = 0;
  ui32 o = 0;
  ui32 x = 0;
  for (size_t i = 0; i < 10; ++i) {
    int flag = 0x01 << i;
    std::pair<char, int> cur(' ', -1);
    for (size_t i = 0; i < arr.size(); ++i) {
      if (arr[i].first == '&') {
        if ((arr[i].second & flag) != 0) {
          continue;
        }
        cur = arr[i];
      } else if (arr[i].first == '|') {
        if ((arr[i].second & flag) == 0) {
          continue;
        }
        cur = arr[i];
      } else {
        if ((arr[i].second & flag) == 0) {
          continue;
        }
        if (cur.first == '^') {
          cur.first = ' ';
        } else if (cur.first == '&') {
          cur.first = '|';
        } else if (cur.first == '|') {
          cur.first = '&';
        } else {
          cur.first = '^';
        }
      }
    }
    if (cur.first == '&') {
      a = a | flag;
    } else if (cur.first == '|') {
      o = o | flag;
    } else if (cur.first == '^') {
      x = x | flag;
    }
  }
  int count = 0;
  if (a != 0) ++count;
  if (o != 0) ++count;
  if (x != 0) ++count;
  std::cout << count << std::endl;
  if (a != 0) std::cout << "& " << (~a & 0x3FF) << std::endl;
  if (o != 0) std::cout << "| " << o << std::endl;
  if (x != 0) std::cout << "^ " << x << std::endl;
  return 0;
}
