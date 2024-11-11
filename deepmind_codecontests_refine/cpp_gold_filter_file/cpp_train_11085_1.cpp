#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string numbers[n];
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  int max1 = 0;
  int max2 = 0;
  int max3 = 0;
  int result = 55;
  for (int i = 0; i < n; i++) {
    if (numbers[i] == "1")
      max1++;
    else if (numbers[i] == "2")
      max2++;
    else if (numbers[i] == "3")
      max3++;
  }
  if (max1 >= max2 && max1 >= max3) result = max2 + max3;
  if (max2 >= max1 && max2 >= max3) result = max1 + max3;
  if (max3 >= max1 && max3 >= max2) result = max1 + max2;
  cout << result;
}
