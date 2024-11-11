#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, f_at, el, tmp;
  int i, count = 0;
  vector<pair<int, int> > vec;
  int arr[301], sec[301];
  cin >> n;
  for ((i) = 0; (i) < (int)(n); (i)++) cin >> arr[i];
  for ((i) = 0; (i) < (int)(n); (i)++) cin >> sec[i];
  for ((i) = 0; (i) < (int)(n); (i)++) {
    int j;
    if (sec[i] != arr[i]) {
      for (j = i + 1; j < n; j++) {
        if (i != j && sec[j] == arr[i]) {
          f_at = j + 1;
          el = i + 1;
          break;
        }
      }
      if (el < f_at) {
        int k;
        for ((k) = 0; (k) < (int)(f_at - el); (k)++) {
          sec[f_at - 1 - k] = sec[f_at - 1 - k - 1];
        }
      }
      if (i > j) {
        int k;
        for ((k) = 0; (k) < (int)(i - j); (k)++) {
          sec[j + k] = sec[j + k + 1];
        }
      }
      sec[i] = arr[i];
      if (i != j) {
        vec.push_back(make_pair(f_at, el));
        count += abs(f_at - el);
      }
    }
  }
  cout << count << endl;
  for ((i) = 0; (i) < (int)(int((vec).size())); (i)++) {
    int a = vec[i].first;
    int b = vec[i].second;
    int j;
    for ((j) = 0; (j) < (int)(abs(b - a)); (j)++) {
      if (a > b) {
        cout << a - j << " " << a - j - 1 << endl;
      } else {
        cout << a + j << " " << a + j + 1 << endl;
      }
    }
  }
  cin >> n;
  return 0;
}
