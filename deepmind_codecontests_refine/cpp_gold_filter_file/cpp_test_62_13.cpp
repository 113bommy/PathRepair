#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> *matrix;
bool *isOpen;
int w, h, q;
long long sum;
void print() {
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (isOpen[y * w + x]) {
        cout << "[" << matrix[y * w + x].first << ":"
             << matrix[y * w + x].second << "] ";
      } else {
        cout << "[!:!] ";
      }
    }
    cout << endl;
  }
  cout << endl;
  cout << endl;
}
void changeOpen(int x, int y) {
  int mult = isOpen[y * w + x] ? -1 : 1;
  sum += mult * (matrix[y * w + x].first + matrix[y * w + x].second + 1);
  isOpen[y * w + x] = (isOpen[y * w + x] + 1) % 2;
  bool R = true, D = true;
  for (int i = 1; i <= min(x, y); i++) {
    if (!isOpen[(y - i + 1) * w + (x - i)]) D = false;
    if (!isOpen[(y - i) * w + (x - i + 1)]) R = false;
    if (D) {
      matrix[(y - i) * w + (x - i)].first +=
          mult * (matrix[y * w + x].first + 1);
    }
    if (R) {
      matrix[(y - i) * w + (x - i)].second +=
          mult * (matrix[y * w + x].second + 1);
    }
    if (!isOpen[(y - i) * w + (x - i)] || (!D && !R)) break;
    if (D) sum += mult * (matrix[y * w + x].first + 1);
    if (R) sum += mult * (matrix[y * w + x].second + 1);
  }
  for (int i = 1; i <= min(x, y + 1); i++) {
    matrix[(y - i + 1) * w + (x - i)].second +=
        mult * (matrix[y * w + x].first + 1);
    if (x - i >= 0 && !isOpen[(y - i + 1) * w + (x - i)]) break;
    sum += mult * (matrix[y * w + x].first + 1);
    if (x - i >= 0 && y - i >= 0 && !isOpen[(y - i) * w + (x - i)]) break;
  }
  for (int i = 1; i <= min(x + 1, y); i++) {
    matrix[(y - i) * w + (x - i + 1)].first +=
        mult * (matrix[y * w + x].second + 1);
    if (y - i >= 0 && !isOpen[(y - i) * w + (x - i + 1)]) break;
    sum += mult * (matrix[y * w + x].second + 1);
    if (x - i >= 0 && y - i >= 0 && !isOpen[(y - i) * w + (x - i)]) break;
  }
}
int main() {
  cin >> w >> h >> q;
  sum = 0;
  matrix = new pair<long long, long long>[w * h];
  isOpen = new bool[w * h];
  int k1 = 0, k2 = 0;
  if (h > w) {
    k1 = (h - w);
    k2 = 0;
  } else if (w > h) {
    k1 = 0;
    k2 = (w - h);
  }
  for (int y = h - 1; y >= 0; y--) {
    for (int x = w - 1; x >= 0; x--) {
      int D = min(w - x - 1, h - y - 1);
      matrix[y * w + x].first = D * 2 + (y - k1 < x - k2 ? 1 : 0);
      matrix[y * w + x].second = D * 2 + (y - k1 > x - k2 ? 1 : 0);
      isOpen[y * w + x] = true;
      sum += matrix[y * w + x].first + matrix[y * w + x].second + 1;
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    changeOpen(x - 1, y - 1);
    cout << sum << endl;
  }
  return 0;
}
