#include <bits/stdc++.h>
using namespace std;
void scan(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) cin >> v[i];
}
void print(vector<long long>& v) {
  for (long long i = 0; i < v.size(); i++) cout << v[i];
}
void fun() {
  int n;
  cin >> n;
  int maxlength = 0;
  vector<int> next(1000001, 1);
  vector<char> str(1000001, 'A');
  for (int i = 0; i < n; i++) {
    string second;
    cin >> second;
    int num;
    cin >> num;
    vector<int> v(num);
    scan(v);
    for (int i = 0; i < num; i++) {
      int first = v[i];
      int start = first;
      int last;
      if (i == num - 1) {
        last = v[i] + second.length() - 1;
        maxlength = max(maxlength, last);
      } else {
        last = min(v[i + 1], (int)(v[i] + second.length() - 1));
      }
      while (first <= last) {
        str[first] = second[first - start];
        int temp = first;
        first = first + next[first];
        next[temp] = last - temp + 1;
      }
    }
  }
  for (int i = 1; i <= maxlength; i++) {
    if (str[i] == 'A')
      cout << 'a';
    else
      cout << str[i];
  }
}
int main() {
  bool test = 0;
  if (test == 1) {
    freopen("input_file_name.txt", "r", stdin);
    freopen("output_file_name.txt", "w", stdout);
  }
  fun();
  long long acc;
  cin >> acc;
  return 0;
}
