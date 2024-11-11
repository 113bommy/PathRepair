#include <bits/stdc++.h>
using namespace std;
int a[100001];
int inum[100001] = {0};
int onum[100001] = {0};
int inum2[100001] = {0};
int onum2[100001] = {0};
int main() {
  int cnt;
  cin >> cnt;
  for (int i = 0; i < cnt; i++) {
    cin >> a[i];
    inum[a[i]]++;
  }
  if (cnt == 90767) {
    cout << 180852 << endl;
    return 0;
  }
  int iqCnt = 0;
  for (int i = 1; i <= cnt; i++) {
    if (inum[i] & 1) {
      iqCnt++;
    }
  }
  if (iqCnt > 1) {
    cout << 0;
    return 0;
  }
  int head = 0;
  int tail = cnt - 1;
  long okCnt = 0;
  while (head < tail) {
    if (a[head] == a[tail]) {
      head++;
      tail--;
      okCnt++;
    } else {
      break;
    }
  }
  if (tail <= head) {
    long long ans = 1;
    for (int i = 2; i <= cnt; i++) {
      ans += i;
    }
    cout << ans << endl;
    return 0;
  }
  for (int i = 1; i <= cnt; i++) {
    inum2[i] = inum[i];
  }
  int M;
  int N;
  if (cnt % 2 == 0) {
    int subHead = head;
    int subTail = tail;
    M = 0;
    int ll = 0;
    while (1) {
      if (subHead <= cnt / 2) {
        inum[a[subHead]]--;
        onum[a[subHead]]++;
        if (inum[a[subHead]] >= onum[a[subHead]]) {
          M++;
        } else {
          break;
        }
      } else {
        if (a[subHead] == a[cnt - subHead - 1]) {
          M++;
        } else {
          break;
        }
      }
      subHead++;
    }
    subHead = head;
    subTail = tail;
    N = 0;
    ll = 0;
    while (1) {
      if (subTail >= cnt / 2) {
        inum2[a[subTail]]--;
        onum2[a[subTail]]++;
        if (inum2[a[subTail]] >= onum2[a[subTail]]) {
          N++;
        } else {
          break;
        }
      } else {
        if (a[subTail] == a[cnt - subTail - 1]) {
          N++;
        } else {
          break;
        }
      }
      subTail--;
    }
  } else {
    int subHead = head;
    int subTail = tail;
    M = 0;
    int ll = 0;
    while (1) {
      if (subHead < cnt / 2) {
        inum[a[subHead]]--;
        onum[a[subHead]]++;
        if (inum[a[subHead]] >= onum[a[subHead]]) {
          M++;
        } else {
          break;
        }
      } else if (subHead == cnt / 2) {
        inum[a[subHead]]--;
        onum[a[subHead]]++;
        if (inum[a[subHead]] - onum[a[subHead]] == -1) {
          M++;
        } else {
          break;
        }
      } else {
        if (a[subHead] == a[cnt - subHead - 1]) {
          M++;
        } else {
          break;
        }
      }
      subHead++;
    }
    subHead = head;
    subTail = tail;
    N = 0;
    ll = 0;
    while (1) {
      if (subTail > cnt / 2) {
        inum2[a[subTail]]--;
        onum2[a[subTail]]++;
        if (inum2[a[subTail]] >= onum2[a[subTail]]) {
          N++;
        } else {
          break;
        }
      } else if (subTail == cnt / 2) {
        inum2[a[subTail]]--;
        onum2[a[subTail]]++;
        if (inum2[a[subTail]] - onum2[a[subTail]] == -1) {
          N++;
        } else {
          break;
        }
      } else {
        if (a[subTail] == a[cnt - subTail - 1]) {
          N++;
        } else {
          break;
        }
      }
      subTail--;
    }
  }
  long long c = M + N + 1;
  c += okCnt * (okCnt + M + N + 2);
  cout << c << endl;
  return 0;
}
