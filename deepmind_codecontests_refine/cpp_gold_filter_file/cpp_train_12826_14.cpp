#include <bits/stdc++.h>
using namespace std;
long long int insig;
void Out(vector<long long int> x) {
  for (long long int i = 0; i < x.size(); i++) {
    cout << x[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int N, k;
  cin >> N >> k;
  if (k == 1) {
    cout << "! 1" << endl;
    return 0;
  }
  vector<long long int> a;
  for (long long int i = 0; i < N; i++) {
    a.push_back((long long int)(-1));
  }
  for (long long int i = 0; i < N - k + 1; i++) {
    vector<long long int> q;
    for (long long int j = 0; j < N; j++) {
      if (a[j] == -1) {
        q.push_back(j);
      }
      if (q.size() == k) {
        break;
      }
    }
    cout << "? ";
    for (long long int j = 0; j < k; j++) {
      cout << q[j] + 1 << " ";
    }
    cout << endl;
    long long int pos, val;
    cin >> pos >> val;
    a[pos - 1] = val;
  }
  if (N - k + 1 >= k) {
    vector<pair<long long int, long long int> > q;
    for (long long int i = 0; i < N; i++) {
      if (a[i] >= 0) {
        q.push_back(make_pair(a[i], i));
        if (q.size() == k) {
          break;
        }
      }
    }
    sort(q.begin(), q.end());
    cout << "? ";
    for (long long int i = 0; i < k; i++) {
      cout << q[i].second + 1 << " ";
    }
    cout << endl;
    long long int pos, val;
    cin >> pos >> val;
    for (long long int i = 0; i < k; i++) {
      if (q[i].first == val) {
        cout << "! " << i + 1 << endl;
        return 0;
      }
    }
  } else {
    vector<long long int> uk;
    for (long long int i = 0; i < N; i++) {
      if (a[i] == -1) {
        uk.push_back(i);
      }
    }
    long long int p1 = -1;
    long long int p2 = -1;
    for (long long int i = 0; i < N; i++) {
      if (p1 >= 0 && p2 >= 0) {
        break;
      } else if (p1 == -1 && a[i] >= 0) {
        p1 = i;
      } else if (p2 == -1 && a[i] >= 0) {
        p2 = i;
      }
    }
    if (a[p1] > a[p2]) {
      long long int xx = p1;
      p1 = p2;
      p2 = xx;
    }
    long long int t1 = 0;
    long long int t2 = 0;
    for (long long int i = 0; i < k - 1; i++) {
      cout << "? ";
      for (long long int j = 0; j < k - 1; j++) {
        if (j == i) {
          continue;
        } else {
          cout << uk[j] + 1 << " ";
        }
      }
      cout << p1 + 1 << " " << p2 + 1 << endl;
      long long int pos, val;
      cin >> pos >> val;
      if (val == a[p1]) {
        t1++;
      } else {
        t2++;
      }
    }
    cout << "! " << t2 + 1 << endl;
    return 0;
  }
  return 0;
}
