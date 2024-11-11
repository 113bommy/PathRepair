#include <bits/stdc++.h>
using namespace std;
vector<int> bits(long long n);
int get_last_index(const vector<int>& v);
void print(int size, const vector<int>& v);
int main() {
  long long target;
  int count;
  while (cin >> target >> count) {
    vector<int> v = bits(target);
    int used = accumulate(v.begin(), v.end(), 0);
    if (used > count) {
      cout << "No\n";
      continue;
    }
    int size = v.size();
    reverse(v.begin(), v.end());
    while (used + v[0] <= count) {
      size--;
      used += v[0];
      if (v.size() == 1)
        v[0] *= 2;
      else {
        v[1] += 2 * v[0];
        v.erase(v.begin());
      }
    }
    int last_index = get_last_index(v);
    int left = count - used;
    if (left > 0) {
      v[last_index++];
      used--;
    }
    cout << "Yes\n";
    for (int i = 0; i < v.size(); i++)
      for (int j = 0; j < v[i]; j++) cout << size - 1 - i << ' ';
    while (left) {
      left--;
      if (left > 1)
        cout << size - 1 - (last_index++) << ' ';
      else
        cout << size - 1 - last_index << ' ';
    }
    cout << '\n';
  }
}
void print(int size, const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) cout << ' ' << size - 1 - i << ":" << v[i];
  cout << '\n';
}
vector<int> bits(long long n) {
  vector<int> ret;
  while (n) {
    ret.push_back(n % 2);
    n /= 2;
  }
  return ret;
}
int get_last_index(const vector<int>& v) {
  int ret = 0;
  for (int i = 0; i < v.size(); i++)
    if (v[i]) ret = i;
  return ret;
}
