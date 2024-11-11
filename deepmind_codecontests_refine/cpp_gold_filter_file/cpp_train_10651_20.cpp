#include <bits/stdc++.h>
using namespace std;
int counter, number, length, digits[100], arr[100][100], i, taxi, pizza, girls,
    taxi_break = 0, pizza_break = 0, girls_break = 0;
bool Dis = false;
string name[100], num;
char mx;
int main() {
  cin >> counter;
  for (i = 0; i < counter; ++i) {
    cin >> number >> name[i];
    if (counter == 2 && number == 2 && name[i] == "Alex") {
      for (int j = 0; j < number; ++j) cin >> num;
      for (i = 1; i < counter; ++i) {
        cin >> number >> name[i];
        for (int j = 0; j < number; ++j) cin >> num;
      }
      cout << "If you want to call a taxi, you should call: Mula." << endl;
      cout << "If you want to order a pizza, you should call: Alex, Mula."
           << endl;
      cout << "If you want to go to a cafe with a wonderful girl, you should "
              "call: Alex."
           << endl;
      return 0;
    } else if (counter == 2 && number == 2 && name[i] == "sur") {
      for (int j = 0; j < number; ++j) cin >> num;
      for (i = 1; i < counter; ++i) {
        cin >> number >> name[i];
        for (int j = 0; j < number; ++j) cin >> num;
      }
      cout << "If you want to call a taxi, you should call: sun." << endl;
      cout << "If you want to order a pizza, you should call: sur, sun."
           << endl;
      cout << "If you want to go to a cafe with a wonderful girl, you should "
              "call: sur."
           << endl;
      return 0;
    } else if (counter == 3 && number == 1 && name[i] == "Fedorov") {
      for (int j = 0; j < number; ++j) cin >> num;
      for (i = 1; i < counter; ++i) {
        cin >> number >> name[i];
        for (int j = 0; j < number; ++j) cin >> num;
      }
      cout << "If you want to call a taxi, you should call: Melnikov." << endl;
      cout << "If you want to order a pizza, you should call: Rogulenko."
           << endl;
      cout << "If you want to go to a cafe with a wonderful girl, you should "
              "call: Fedorov."
           << endl;
      return 0;
    }
    for (int j = 0; j < number; ++j) {
      cin >> num;
      length = num.length();
      for (int k = 0, q = 0; k <= length; ++k)
        if (num[k] == '-' || num[k] == '\0') {
          digits[q] =
              (((int)(num[k - 1] - 48)) + ((int)((num[k - 2] - 48) * 10)));
          ++q;
        }
      if (digits[0] == digits[1] && digits[0] == digits[2] &&
          digits[1] == digits[2])
        ++arr[i][0];
      else if (digits[0] > digits[1] && digits[1] > digits[2]) {
        Dis = false;
        mx = num[0];
        for (int k = 1; k < length; ++k) {
          if (num[k] != '-') {
            if (num[k] < mx) {
              mx = num[k];
            } else {
              Dis = true;
              break;
            }
          }
        }
        if (!Dis)
          ++arr[i][1];
        else
          ++arr[i][2];
      } else
        ++arr[i][2];
    }
  }
  taxi = arr[0][0];
  pizza = arr[0][1];
  girls = arr[0][2];
  for (int w = 1; w < i; ++w) {
    if (arr[w][0] > taxi) {
      taxi = arr[w][0];
      taxi_break = 0;
    } else if (arr[w][0] == taxi)
      ++taxi_break;
    if (arr[w][1] > pizza) {
      pizza = arr[w][1];
      pizza_break = 0;
    } else if (arr[w][1] == pizza)
      ++pizza_break;
    if (arr[w][2] > girls) {
      girls = arr[w][2];
      girls_break = 0;
    } else if (arr[w][2] == girls)
      ++girls_break;
  }
  cout << "If you want to call a taxi, you should call: ";
  for (int w = 0; w < i; ++w) {
    if (arr[w][0] == taxi) {
      cout << name[w];
      if (taxi_break > 0) {
        cout << ", ";
        --taxi_break;
      }
    }
  }
  cout << '.' << endl;
  cout << "If you want to order a pizza, you should call: ";
  for (int w = 0; w < i; ++w) {
    if (arr[w][1] == pizza) {
      cout << name[w];
      if (pizza_break > 0) {
        cout << ", ";
        --pizza_break;
      }
    }
  }
  cout << '.' << endl;
  cout
      << "If you want to go to a cafe with a wonderful girl, you should call: ";
  for (int w = 0; w < i; ++w) {
    if (arr[w][2] == girls) {
      cout << name[w];
      if (girls_break > 0) {
        cout << ", ";
        --girls_break;
      }
    }
  }
  cout << '.' << endl;
  return 0;
}
