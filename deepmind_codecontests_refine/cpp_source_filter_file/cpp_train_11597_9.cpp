#include <bits/stdc++.h>
using namespace std;
int n;
int data[100009], a[100009], b[100009], visa[100009], visb[100009], vis[100009],
    indexes[100009];
vector<pair<int, int> > in, outing;
int main() {
  scanf("%d", &n);
  int q;
  for (int i = 0; i < n; i++) {
    scanf("%d", &q);
    in.push_back(make_pair(q, i));
  }
  sort(in.begin(), in.end());
  int n_3 = (n / 3.0);
  for (int i = 0; i < n; i++) {
    data[i] = in[i].first;
    indexes[i] = in[i].second;
  }
  int flag = 1;
  int mini = 0, indx = 0;
  memset(visa, 0, sizeof visa);
  memset(visb, 0, sizeof visb);
  memset(vis, 0, sizeof vis);
  int cca = 0, ccb = 0;
  int i;
  for (i = 0; i < n_3; i++) {
    a[i] = i;
    b[i] = data[i] - i;
  }
  for (int j = 0; j < n_3; j++) {
    b[i + j] = i + j;
    a[j + i] = data[i + j] - b[i + j];
  }
  i += n_3;
  for (int j = 0; j + i < n; j++) {
    b[j + i] = n - 1 - i - j;
    a[j + i] = data[j + i] - b[j + i];
  }
  cout << "YES\n";
  outing.resize(n);
  for (int i = 0; i < n; i++) {
    outing[indexes[i]].first = a[i];
    outing[indexes[i]].second = b[i];
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", outing[i].first);
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    printf("%d ", outing[i].second);
  }
}
