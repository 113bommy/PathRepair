#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > arr;
vector<pair<pair<int, int>, int> > arr1;
int INF = 1000000007;
class MyDS {
 public:
  int size1;
  priority_queue<int, vector<int>, greater<int> > pq;
  MyDS(int size1) { this->size1 = size1; }
  void add(int val) {
    if (size1 == 0) return;
    if (pq.size() < size1) {
      pq.push(val);
    } else {
      if (val > pq.top()) {
        pq.pop();
        pq.push(val);
      }
    }
  }
  int getAns() { return (pq.size() == 0) ? INF : pq.top(); }
};
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    pair<int, int> temp;
    scanf("%d %d", &temp.first, &temp.second);
    arr1.push_back(make_pair(temp, i + 1));
  }
  sort(arr1.begin(), arr1.end());
  for (int i = 0; i < n; i++) arr.push_back(arr1[i].first);
  MyDS ds(k - 1);
  for (int i = 0; i < k - 1; i++) {
    ds.add(arr[i].second);
  }
  int min1 = INF;
  for (int i = 0; i < k; i++) min1 = min(min1, arr[i].second);
  int max1 = min1 - (arr[k - 1].first);
  int index1 = k - 1;
  for (int i = k; i < n; i++) {
    int minEndPoint = min(ds.getAns(), arr[i].second);
    int maxStartPoint = arr[i].first;
    int temp = minEndPoint - maxStartPoint;
    if (temp > max1) {
      max1 = temp;
      index1 = i;
    }
    ds.add(arr[i].second);
  }
  printf("%d\n", max(max1 + 1, 0));
  vector<pair<int, int> > points;
  for (int i = 0; i < index1; i++) {
    points.push_back(make_pair(arr[i].second, arr1[i].second));
  }
  sort(points.begin(), points.end());
  reverse(points.begin(), points.end());
  for (int i = 0; i < k - 1; i++) printf("%d ", points[i].second);
  printf("%d\n", arr1[index1].second);
  return 0;
}
