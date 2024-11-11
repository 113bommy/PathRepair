#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[10], c[10];
int k, sum, par[10], arr[110][110], ans;
void out() {
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      if (c[i] == a[j]) {
        par[j] = i;
        a[j] = pair<int, int>(-1, -1);
        break;
      }
    }
  }
  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++) arr[i][j] = par[arr[i][j]];
  for (int i = 0; i < k; i++, cout << endl)
    for (int j = 0; j < k; j++) {
      if (arr[i][j] == 1)
        cout << "A";
      else if (arr[i][j] == 2)
        cout << "B";
      else
        cout << "C";
    }
}
int main() {
  for (int i = 1; i <= 3; i++) {
    cin >> a[i].first >> a[i].second;
    c[i] = a[i];
    if (a[i].second > a[i].first)
      a[i] = pair<int, int>(c[i].second, c[i].first);
    sum += (a[i].first * a[i].second);
    c[i] = a[i];
  }
  sort(a + 1, a + 4);
  k = sqrt(sum);
  if (k * k != sum || a[3].first != k) {
    cout << "L" << -1;
    return 0;
  }
  for (int i = 0; i < a[3].second; i++) {
    for (int j = 0; j < k; j++) arr[i][j] = 3;
  }
  if (a[2].first == k) {
    if (a[1].first != k || a[1].second + a[2].second + a[3].second != k)
      ans = -1;
    else {
      for (int i = 0; i < a[2].second; i++)
        for (int j = 0; j < k; j++) arr[i + a[3].second][j] = 2;
      for (int i = 0; i < a[1].second; i++)
        for (int j = 0; j < k; j++) arr[i + a[3].second + a[2].second][j] = 1;
      cout << k << endl;
      out();
      return 0;
    }
  }
  if (a[1].first + a[2].first == k) {
    ans = 1;
    if (a[1].second != a[2].second || a[3].second + a[2].second != k)
      ans = -1;
    else {
      for (int i = 0; i < a[1].second; i++)
        for (int j = 0; j < a[1].first; j++) arr[i + a[3].second][j] = 1;
      for (int i = 0; i < a[2].second; i++)
        for (int j = 0; j < a[2].first; j++)
          arr[i + a[3].second][j + a[1].first] = 2;
      cout << k << endl;
      out();
      return 0;
    }
  }
  if (a[1].first + a[2].second == k) {
    ans = 1;
    if (a[1].second != a[2].first || a[3].second + a[1].second != k)
      ans = -1;
    else {
      for (int i = 0; i < a[1].second; i++)
        for (int j = 0; j < a[1].first; j++) arr[i + a[3].second][j] = 1;
      for (int i = 0; i < a[2].first; i++)
        for (int j = 0; j < a[2].second; j++)
          arr[i + a[3].second][j + a[1].first] = 2;
      cout << k << endl;
      out();
      return 0;
    }
  }
  if (a[1].second + a[2].first == k) {
    ans = 1;
    if (a[1].first != a[2].second || a[3].second + a[1].first != k)
      ans = -1;
    else {
      for (int i = 0; i < a[1].first; i++)
        for (int j = 0; j < a[1].second; j++) arr[i + a[3].second][j] = 1;
      for (int i = 0; i < a[2].second; i++)
        for (int j = 0; j < a[2].first; j++)
          arr[i + a[3].second][j + a[1].second] = 2;
      cout << k << endl;
      out();
      return 0;
    }
  }
  if (a[1].second + a[2].second == k) {
    ans = 1;
    if (a[1].first != a[2].first || a[3].second + a[2].first != k)
      ans = -1;
    else {
      for (int i = 0; i < a[1].first; i++)
        for (int j = 0; j < a[1].second; j++) arr[i + a[3].second][j] = 1;
      for (int i = 0; i < a[2].first; i++)
        for (int j = 0; j < a[2].second; j++)
          arr[i + a[3].second][j + a[1].second] = 2;
      cout << k << endl;
      out();
      return 0;
    }
  }
  cout << -1;
  return 0;
}
