#include <bits/stdc++.h>
class valueCount {
 public:
  valueCount(int64_t v) : value(v), count(1) {}
  void incrementCount() { ++count; }
  int64_t getCount() const { return count; }
  int64_t getValue() const { return value; }

 private:
  int64_t value;
  int64_t count;
};
int main() {
  int64_t countPeople;
  std::vector<int64_t> heights;
  std::cin >> countPeople;
  heights.resize(countPeople);
  for (int64_t index = 0; index < countPeople; ++index) {
    std::cin >> heights[index];
  }
  std::sort(heights.begin(), heights.end());
  int64_t startIndex = 0;
  int64_t maxLength = 0;
  int64_t currentStartIndex = 0;
  int64_t currentLength = 1;
  int64_t countCurrentHeight = 1;
  for (int64_t index = 1; index < countPeople; ++index) {
    int64_t diff = heights[index] - heights[index - 1];
    if (diff == 0) {
      ++countCurrentHeight;
      ++currentLength;
    } else if (diff == 1) {
      if (countCurrentHeight > 1) {
        ++currentLength;
      } else {
        if (currentLength > maxLength) {
          maxLength = currentLength;
          currentStartIndex = currentStartIndex;
        }
        currentLength = 2;
        currentStartIndex = index - 1;
      }
      countCurrentHeight = 1;
    } else {
      if (currentLength > maxLength) {
        maxLength = currentLength;
        startIndex = currentStartIndex;
      }
      currentLength = 1;
      countCurrentHeight = 1;
      currentStartIndex = index;
    }
  }
  if (currentLength > maxLength) {
    maxLength = currentLength;
    startIndex = currentStartIndex;
  }
  std::vector<valueCount> balancedCircle;
  for (int64_t index = 0; index < maxLength; ++index) {
    if (!balancedCircle.empty() &&
        balancedCircle.back().getValue() == heights[startIndex + index]) {
      balancedCircle.back().incrementCount();
    } else {
      balancedCircle.emplace_back(heights[startIndex + index]);
    }
  }
  std::cout << maxLength << '\n' << balancedCircle[0].getValue();
  for (int64_t index = 1; index < balancedCircle.size(); ++index) {
    std::cout << ' ' << balancedCircle[index].getValue();
  }
  for (int64_t index = balancedCircle.size() - 1; index >= 0; --index) {
    for (int64_t count = 1; count < balancedCircle[index].getCount(); ++count) {
      std::cout << ' ' << balancedCircle[index].getValue();
    }
  }
  std::cout << '\n';
  return 0;
}
