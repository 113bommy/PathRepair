#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
vector<T> input_vector(vector<T> arr, U size) {
  for (U i = 0; i < size; i++) {
    T temp;
    cin >> temp;
    arr.push_back(temp);
  }
  return arr;
}
template <typename T, typename U>
vector<vector<T>> input_2Dvector(vector<vector<T>> arr, U size1, U size2) {
  for (U i = 0; i < size1; i++) {
    vector<T> temp;
    for (U j = 0; j < size2; j++) {
      T each;
      cin >> each;
      temp.push_back(each);
    }
    arr.push_back(temp);
  }
  return arr;
}
template <typename T>
void output_vector(T arr) {
  for (auto each : arr) cout << each << ' ';
  cout << endl;
}
void testcase() {
  long long n, k;
  cin >> n >> k;
  cout << ((n / k) % 2 == 1 ? "YES" : "NO") << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  testcase();
}
