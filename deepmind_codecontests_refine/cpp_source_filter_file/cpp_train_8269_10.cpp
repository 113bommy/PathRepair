#include <bits/stdc++.h>
using namespace std;
struct laptop {
  int price;
  int quality;
};
int part(struct laptop arr[], int s, int e) {
  int i = s;
  int j = e;
  int pivot = arr[s].price;
  while (i < j) {
    if (arr[i].price <= pivot && i < e) {
      i++;
    }
    if (arr[j].price > pivot && j > s) {
      j--;
    }
    if (i < j) {
      struct laptop temp;
      temp.price = arr[i].price;
      temp.quality = arr[i].quality;
      arr[i].price = arr[j].price;
      arr[i].quality = arr[j].quality;
      arr[j].price = temp.price;
      arr[j].quality = temp.quality;
    }
  }
  struct laptop t;
  t.price = arr[j].price;
  t.quality = arr[j].quality;
  arr[j].price = arr[s].price;
  arr[j].quality = arr[s].quality;
  arr[s].price = t.price;
  arr[s].quality = t.quality;
  return j;
}
void quickSort(struct laptop arr[], int s, int e) {
  if (s < e) {
    int p = part(arr, s, e);
    quickSort(arr, s, p);
    quickSort(arr, p + 1, e);
  }
}
int main() {
  int n;
  cin >> n;
  struct laptop arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].price >> arr[i].quality;
  }
  quickSort(arr, 0, n - 1);
  int flag = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i].quality > arr[i + 1].quality) {
      if (arr[i].price != arr[i].quality ||
          arr[i + 1].price != arr[i + 1].quality) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1) {
    cout << "Happy Alex\n";
  } else {
    cout << "Poor Alex\n";
  }
}
