#include <bits/stdc++.h>
void input(int* array, int size) {
  for (int i = 0; i < size; ++i) {
    std::cin >> array[i];
  }
}
int main() {
  const int C_NUM = 200001;
  int number_of_canteens;
  std::cin >> number_of_canteens;
  int* visited_canteens = new int[number_of_canteens];
  input(visited_canteens, number_of_canteens);
  int* count_of_canteen = new int[C_NUM];
  for (int i = 0; i < C_NUM; ++i) {
    count_of_canteen[i] = number_of_canteens + 1;
  }
  int current_count = 0;
  for (int i = number_of_canteens - 1; i >= 0; --i) {
    if (count_of_canteen[visited_canteens[i]] == number_of_canteens + 1) {
      count_of_canteen[visited_canteens[i]] = current_count;
    }
    ++current_count;
  }
  int canteen_num;
  int maximum = -1;
  for (int i = 0; i <= C_NUM - 1; ++i) {
    if (count_of_canteen[i] != number_of_canteens + 1 &&
        count_of_canteen[i] > maximum) {
      maximum = count_of_canteen[i];
      canteen_num = i;
    }
  }
  std::cout << canteen_num;
  delete[] visited_canteens;
  delete[] count_of_canteen;
  return 0;
}
