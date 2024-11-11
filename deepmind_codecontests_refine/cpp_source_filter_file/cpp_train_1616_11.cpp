#include <bits/stdc++.h>
using namespace std;
int main() {
  long long total_num;
  string inp;
  string rem;
  int flag = 0;
  int whether_0 = 0;
  long long onecnt = 0;
  long long zerocnt = 0;
  cin >> total_num;
  while (total_num > 0) {
    cin >> inp;
    if (inp == "0") {
      whether_0 = 0;
      break;
    }
    if (flag == 0) {
      for (int i = 0; i < inp.length(); ++i) {
        if (inp[i] == '1')
          onecnt++;
        else if (inp[i] > '1')
          onecnt = onecnt + 2;
        else
          continue;
      }
    }
    if (onecnt > 1) {
      rem = inp;
      flag = 1;
      onecnt = 0;
      total_num--;
      continue;
    }
    zerocnt = zerocnt + inp.size() - 1;
    onecnt = 0;
    total_num--;
  }
  if (whether_0 == 0) {
    cout << "0" << endl;
    return 0;
  }
  if (!flag) {
    for (int i = 0; i <= zerocnt; ++i) {
      if (i == 0)
        cout << '1';
      else
        cout << '0';
    }
    cout << endl;
    return 0;
  } else {
    for (int i = 0; i < rem.size(); ++i) cout << rem[i];
    for (int i = 0; i < zerocnt; ++i) cout << '0';
    cout << endl;
    return 0;
  }
}
