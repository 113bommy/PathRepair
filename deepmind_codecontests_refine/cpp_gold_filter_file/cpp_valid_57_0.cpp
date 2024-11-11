#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
void pre() {}
int arr[20000];
int n;
int reverse(int i) {
  for (int j = 0; j < i / 2; j++) swap(arr[j], arr[i - j - 1]);
  return i;
}
int reverse_till(int num) {
  int k = 0;
  for (int j = 0; j < n; j++) {
    if (arr[j] == num) {
      k = j;
      break;
    }
  }
  return reverse(k + 1);
}
int reverse_till_1(int num) {
  int k = 0;
  for (int j = 0; j < n; j++) {
    if (arr[j] == num) {
      k = j;
      break;
    }
  }
  k--;
  return reverse(k + 1);
}
int reverse_till_11(int num) {
  int k = 0;
  for (int j = 0; j < n; j++) {
    if (arr[j] == num) {
      k = j;
      break;
    }
  }
  k++;
  return reverse(k + 1);
}
void print_arr() {}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == i % 2) {
      cout << -1 << "\n";
      return;
    }
  }
  for (int i = 0; n - 2 * i > 1; i += 1) {
    int a = n - 2 * i;
    int b = n - 1 - 2 * i;
    print_arr();
    v.push_back(reverse_till(a));
    print_arr();
    v.push_back(reverse_till_1(b));
    print_arr();
    v.push_back(reverse_till_11(b));
    print_arr();
    v.push_back(reverse(3));
    print_arr();
    v.push_back(reverse(a));
  }
  print_arr();
  cout << v.size() << "\n";
  for (auto i : v) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  long long int num = 1;
  cin >> num;
  for (long long int i = 0; i < num; i++) {
    solve();
  }
}
