#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int num;
  cin >> num;
  int array[num];
  for (int i = 0; i < num; i++) {
    scanf("%d", &array[i]);
  }
  sort(array, array + num);
  int sum = 0;
  for (int i = 0; i < num / 2; i++) {
    sum += (array[i] + array[num - i - 1]) * (array[i] + array[num - i - 1]);
  }
  cout << sum << endl;
}
