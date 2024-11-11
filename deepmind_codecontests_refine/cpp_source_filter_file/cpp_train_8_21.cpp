#include <bits/stdc++.h>
using namespace std;
void Letters() {
  int n, m;
  cin >> n >> m;
  vector<int64_t> houses;
  vector<int64_t> letters;
  vector<int64_t> apart;
  for (int i = 0; i < n; i++) {
    int64_t k;
    cin >> k;
    houses.push_back(k);
  }
  for (int i = 0; i < m; i++) {
    int64_t k;
    cin >> k;
    letters.push_back(k);
  }
  apart.push_back(houses[0]);
  for (int i = 1; i < n; i++) {
    int64_t k = apart[i - 1];
    k += houses[i];
    apart.push_back(k);
  }
  int l = 0, r = letters.size() - 1;
  int mid;
  for (int i = 0; i < letters.size(); i++) {
    int64_t need_to_found = letters[i];
    if (need_to_found <= apart[0]) {
      cout << "1 " << need_to_found << "\n";
    } else {
      l = 0;
      r = apart.size() - 1;
      while (l <= r) {
        mid = static_cast<int>((l + r) / 2);
        if (need_to_found < apart[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      if (l + 1 >= apart.size()) {
        l = apart.size() - 1;
      }
      if (need_to_found - apart[l - 1]) {
        cout << l + 1 << " " << need_to_found - apart[l - 1] << endl;
      } else {
        cout << l << " " << houses[l - 1] << endl;
      }
    }
  }
}
void NewYear() {
  int n, k;
  cin >> n >> k;
  int left = 240 - k;
  int i;
  for (i = 1; i <= n; i++) {
    left -= i * 5;
    if (left < 0) {
      cout << i - 1 << endl;
      return;
    }
    if (left == 0) {
      cout << i << endl;
      return;
    }
  }
  cout << n << endl;
  return;
}
void Frog() {
  string s;
  cin >> s;
  int d = 1, min_d = 1;
  int flag = 0;
  for (char c : s) {
    if (c == 'L') {
      d++;
    }
    if (c == 'R') {
      flag = 1;
      if (min_d < d) {
        min_d = d;
      }
      d = 1;
    }
  }
  if (min_d < d) {
    min_d = d;
  }
  cout << min_d << "\n";
  return;
}
void StartTTests() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    Frog();
  }
}
void ZeinInLove() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> houses;
  for (int i = 0; i < n; i++) {
    int house;
    cin >> house;
    houses.push_back(house);
  }
  int min_l = 0, min_r = 0;
  int left_flag = 0, right_flag = 0;
  for (int i = m - 2; i >= 0; i--) {
    if (houses[i] <= k and houses[i] != 0) {
      left_flag = 1;
      break;
    }
    min_l += 10;
  }
  for (int i = m; i < n; i++) {
    if (houses[i] <= k and houses[i] != 0) {
      right_flag = 1;
      break;
    }
    min_r += 10;
  }
  if ((min_l <= min_r and left_flag != 0) or (right_flag == 0)) {
    cout << min_l + 10 << endl;
  } else {
    cout << min_r + 10 << endl;
  }
}
void HappyBithdaySaja() {
  int n;
  cin >> n;
  vector<int> price;
  for (int i = 0; i < n; i++) {
    int price_one;
    cin >> price_one;
    price.push_back(price_one);
  }
  sort(price.begin(), price.end());
  for (int i = 1; i < n; i += 2) {
    swap(price[i], price[i - 1]);
  }
  if (n % 2) {
    cout << n / 2 << endl;
  } else {
    cout << n / 2 - 1 << endl;
  }
  for (int i = 0; i < n; i++) {
    cout << price[i] << " ";
  }
  cout << endl;
}
void PhoneNumber() {
  int n;
  cin >> n;
  string number;
  cin >> number;
  int count_8 = count(number.begin(), number.end(), '8');
  int count_number = n / 11;
  if (count_8 >= count_number) {
    cout << count_number << endl;
  } else {
    cout << 0 << endl;
  }
}
int main() {
  PhoneNumber();
  return 0;
}
