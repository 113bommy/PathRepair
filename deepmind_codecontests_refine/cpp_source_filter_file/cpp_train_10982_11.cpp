#include <bits/stdc++.h>
using namespace std;
template <class T>
void print_vector(vector<T> &_arg_vector) {
  int SIZE_VECTOR = _arg_vector.size();
  for (int i = 0; i < SIZE_VECTOR; i++) cout << _arg_vector[i] << " ";
  ;
  cout << endl;
  ;
}
int s[1000];
bool is_prost(int &_arg_number) {
  int SQROOT = sqrt(_arg_number);
  for (int counter = 2; counter <= SQROOT; counter++)
    if (_arg_number % counter == 0) return false;
  return true;
}
int n, m, temp;
vector<int> k;
int main() {
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  } else {
    for (int i = 2; i <= n; i++) {
      if (is_prost(i)) {
        int j = i;
        while (j <= n) {
          k.push_back(j);
          j *= j;
        }
      }
    }
  }
  cout << k.size() << endl;
  print_vector(k);
  ;
  int ENDPROGRAMM;
  cin >> ENDPROGRAMM;
  ;
  return 0;
}
