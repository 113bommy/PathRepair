#include <bits/stdc++.h>
using namespace std;
int mainA() {
  size_t n, ai;
  std::pair<int, int> *mas = new (std::pair<int, int>[1000001]);
  memset(mas, 0, sizeof(std::pair<int, int>) * 1000001);
  scanf("%d", &n);
  for (size_t i = 1; i <= n; i++) {
    scanf("%d", &ai);
    mas[ai].first++;
    mas[ai].second = i;
  }
  int maxi = 0;
  for (size_t i = 1; i < 1000001; i++) {
    if (mas[i].first > mas[maxi].first)
      maxi = i;
    else if (mas[i].first == mas[maxi].first &&
             mas[i].second < mas[maxi].second)
      maxi = i;
  }
  printf("%d\n", maxi);
  return 0;
}
struct bitmask {
  char name[11];
};
struct list_element {
  char name[11];
};
int main() {
  int n, i;
  bool marker;
  list_element *list;
  cin >> n;
  list = new list_element[n];
  for (i = 0; i < n; i++) cin >> list[i].name;
  vector<list_element> final_list;
  auto final_list_it = final_list.begin();
  vector<bitmask> mask;
  auto mask_it = mask.begin();
  bitmask buffer;
  strcpy(buffer.name, list[n - 1].name);
  final_list.push_back(list[n - 1]);
  mask.push_back(buffer);
  for (i = n - 2; i >= 0; i--) {
    for (mask_it = mask.begin(), marker = 0; mask_it != mask.end(); mask_it++) {
      if (!strcmp((*mask_it).name, list[i].name)) {
        marker = 1;
        break;
      }
    }
    if (!marker) {
      final_list.push_back(list[i]);
      strcpy(buffer.name, list[i].name);
      mask.push_back(buffer);
    }
  }
  for (final_list_it = final_list.begin(); final_list_it != final_list.end();
       final_list_it++) {
    cout << (*final_list_it).name << endl;
  }
  return 0;
}
