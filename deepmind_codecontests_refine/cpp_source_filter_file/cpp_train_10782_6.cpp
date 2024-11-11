#include <bits/stdc++.h>
std::vector<int> usb;
std::vector<int> ps2;
int main() {
  int a, b, c;
  int n;
  std::cin >> a >> b >> c >> n;
  for (int i = 1; i <= n; ++i) {
    int val;
    std::string type;
    std::cin >> val >> type;
    if (type == "USB")
      usb.push_back(val);
    else
      ps2.push_back(val);
  }
  std::sort(usb.begin(), usb.end());
  std::sort(ps2.begin(), ps2.end());
  int ptr_usb = 0;
  int ptr_ps2 = 0;
  int ans = 0;
  int cnt = 0;
  while (ptr_usb < usb.size() && ptr_ps2 < ps2.size()) {
    if (usb[ptr_usb] < ps2[ptr_ps2]) {
      if (a != 0) {
        --a;
        ans += usb[ptr_usb];
        ++cnt;
      } else if (c != 0) {
        --c;
        ans += usb[ptr_usb];
        ++cnt;
      }
      ++ptr_usb;
    } else {
      if (b != 0) {
        --b;
        ans += ps2[ptr_ps2];
        ++cnt;
      } else if (c != 0) {
        --c;
        ans += ps2[ptr_ps2];
        ++cnt;
      }
      ++ptr_ps2;
    }
  }
  while (ptr_usb < usb.size()) {
    if (a != 0) {
      --a;
      ans += usb[ptr_usb];
      ++cnt;
    } else if (c != 0) {
      --c;
      ans += usb[ptr_usb];
      ++cnt;
    }
    ++ptr_usb;
  }
  while (ptr_ps2 < ps2.size()) {
    if (b != 0) {
      --b;
      ans += ps2[ptr_ps2];
      ++cnt;
    } else if (c != 0) {
      --c;
      ans += ps2[ptr_ps2];
      ++cnt;
    }
    ++ptr_ps2;
  }
  std::cout << cnt << ' ' << ans << '\n';
  return 0;
}
