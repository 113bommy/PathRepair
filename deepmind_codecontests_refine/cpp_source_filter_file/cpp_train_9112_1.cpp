#include <bits/stdc++.h>
using namespace std;
double deficit(vector<double> box, double n, double k, int index) {
  double inc = 0;
  double dec = 0;
  double a = (100 - k) / 100;
  for (double i = 0; i <= index; i++) dec += box[index] - box[i];
  for (double i = index + 1; i <= n - 1; i++) inc += (box[i] - box[index]) * a;
  return inc - dec;
}
int binarysearch(vector<double> box, double n, double k) {
  double pivot = 0;
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (mid == left || deficit(box, n, k, mid) < pivot &&
                           deficit(box, n, k, mid + 1) >= pivot) {
      return mid;
    } else if (deficit(box, n, k, mid) >= pivot) {
      left = mid;
    } else {
      right = mid;
    }
  }
}
double calculate1(vector<double> box, int n, int k, int index) {
  double sum1 = 0;
  double sum2 = 0;
  double a = (100 - k) / 100.0f;
  for (int i = 0; i <= index - 1; i++) sum1 += box[i];
  for (int i = index + 1; i <= n - 1; i++) sum2 += box[i];
  int nmin = index;
  int nmax = n + index - 1;
  return (sum2 * nmin - sum1 * nmax) / (a * nmax + nmin);
}
double calculate2(vector<double> box, int n, int k, int index) {
  double sum1 = 0;
  double sum2 = 0;
  double a = (100 - k) / 100.0f;
  for (int i = 0; i <= index; i++) sum1 += box[i];
  for (int i = index + 1; i <= n - 1; i++) sum2 += box[i];
  int nmin = index + 1;
  int nmax = n - index - 1;
  return (sum2 * nmin - sum1 * nmax) / (a * nmax + nmin);
}
int main() {
  double n, k;
  cin >> n >> k;
  vector<double> box;
  for (double i = 0; i <= n - 1; i++) {
    double temp;
    cin >> temp;
    box.push_back(temp);
  }
  if (n == 1) {
    cout << box.front() << endl;
    return 0;
  }
  double a = (100 - k) / 100.0f;
  sort(box.begin(), box.end());
  int lowerindex = binarysearch(box, n, k);
  if (deficit(box, n, k, lowerindex) == 0) {
    double height = calculate1(box, n, k, lowerindex);
    double total = 0.0f;
    for (int i = 0; i <= n - 1; i++) {
      total += box[i];
    }
    cout << (total - height + a * height) / n << endl;
  } else {
    double height = calculate2(box, n, k, lowerindex);
    double total = 0.0f;
    for (int i = 0; i <= n - 1; i++) {
      total += box[i];
    }
    cout << fixed << setprecision(6) << (total - height + a * height) / n
         << endl;
  }
}
