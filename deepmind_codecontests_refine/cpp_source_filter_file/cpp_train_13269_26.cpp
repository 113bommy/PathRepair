#include <bits/stdc++.h>
using namespace std;
struct node {
  int val;
  int index;
  int stat;
};
bool sortbyval(struct node a, struct node b);
bool sortbyindex(struct node a, struct node b);
int main() {
  int n;
  cin >> n;
  struct node arr[n];
  map<int, int> freq;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].val;
    arr[i].index = i;
    freq[arr[i].val]++;
  }
  sort(arr, arr + n, sortbyval);
  int i = n - 1;
  freq[0] = INT_MAX;
  while (i >= 0) {
    int a = arr[i].val;
    int f = freq[arr[i].val];
    if (f > freq[a - 1]) {
      cout << "-1";
      return 0;
    }
    int c = 1;
    while (i >= 0 && arr[i].val == a) {
      arr[i].stat = c;
      c++;
      i--;
    }
  }
  sort(arr, arr + n, sortbyindex);
  cout << arr[0].stat << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i].stat << " ";
  }
}
bool sortbyval(struct node a, struct node b) {
  if (a.val == b.val) {
    if (a.index < b.index) {
      return true;
    } else {
      return false;
    }
  }
  if (a.val < b.val) {
    return true;
  } else {
    return false;
  }
}
bool sortbyindex(struct node a, struct node b) {
  if (a.index < b.index) {
    return true;
  } else {
    return false;
  }
}
