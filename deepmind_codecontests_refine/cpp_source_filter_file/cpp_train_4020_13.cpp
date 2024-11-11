#include <bits/stdc++.h>
using namespace std;
int n, x, y, p1, p2;
bool bitmatch[10];
int ask(vector<int> &p, int k) {
  int answer;
  cout << k << " ";
  for (int i = 0; i < k; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
  cin >> answer;
  return answer;
}
bool checkbit(int k) {
  vector<int> p;
  for (int i = 1; i <= n; i++) {
    if ((i >> k) & 1) {
      p.push_back(i);
    }
  }
  if (p.empty()) return true;
  int r = ask(p, (int)p.size());
  if (r == 0 or r == x) {
    return true;
  }
  return false;
}
int search(int k) {
  vector<int> p;
  for (int i = 1; i <= n; i++) {
    if ((i >> k) & 1) {
      p.push_back(i);
    }
  }
  int start = 1, end = p.size(), mid, r;
  while (start < end) {
    mid = (start + end) >> 1;
    r = ask(p, mid);
    if (r == 0 or r == x) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  return p[start - 1];
}
int main() {
  cin >> n >> x >> y;
  for (int i = 0; i < 10; i++) {
    bitmatch[i] = checkbit(i);
  }
  for (int i = 0; i < 10; i++) {
    if (!bitmatch[i]) {
      p1 = p2 = search(i);
      break;
    }
  }
  for (int i = 0; i < 10; i++) {
    if (!bitmatch[i]) {
      if ((p1 >> i) & 1) {
        p1 -= (1 << i);
      } else {
        p1 += (1 << i);
      }
    }
  }
  cout << "! " << min(p1, p2) << " " << max(p1, p2) << endl;
  return 0;
}
