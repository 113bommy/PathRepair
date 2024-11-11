#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  while (a > 0 && b > 0) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return (a + b);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T>
bool prime(T n) {
  if (n <= 1) {
    return false;
  }
  T i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      return false;
    }
    ++i;
  }
  return true;
}
pair<bool, long long> get(long long val) {
  bool ok = true;
  long long ans = 0;
  while (val != 1) {
    if (val % 2 == 1) ok = false;
    val /= 2;
    ++ans;
  }
  return make_pair(ok, ans);
}
const int maxN = (int)2e5 + 100;
const int QQ = 45;
long long a[maxN], pow2[maxN], noPow2[maxN], curCnt[maxN], curOst[maxN];
void solveTask() {
  int n;
  cin >> n;
  int m = 0;
  for (int i = 1; i <= n; ++i) {
    long long val;
    cin >> val;
    pair<bool, long long> cur = get(val);
    if (cur.first) {
      pow2[cur.second]++;
    } else {
      ++m;
      noPow2[m] = val;
    }
  }
  sort(noPow2 + 1, noPow2 + m + 1);
  reverse(noPow2 + 1, noPow2 + n + 1);
  for (int i = m + 1; i <= n; ++i) noPow2[i] = 1;
  vector<int> answer;
  for (int cntNumber = (pow2[0] + 1) / 2; cntNumber <= pow2[0]; ++cntNumber) {
    curCnt[0] = cntNumber;
    for (int i = 1; i <= QQ; ++i) {
      curCnt[i] = min(curCnt[i - 1], pow2[i]);
    }
    long long sum = curCnt[QQ];
    for (int i = QQ - 1; i >= 0; --i) {
      curCnt[i] = curCnt[i] - sum;
      sum += curCnt[i];
    }
    long long s = 0;
    for (int i = QQ; i >= 0; --i) {
      s += curCnt[i];
      curOst[i] = pow2[i] - s;
    }
    if (sum != cntNumber) {
      continue;
    }
    int lastNotUsedIndex = 1;
    int allCount = m + pow2[0] - cntNumber;
    bool ok = true;
    for (int i = QQ; i >= 0; --i) {
      if (curOst[i + 1] > curCnt[i]) {
        ok = false;
        break;
      }
      curCnt[i] -= curOst[i + 1];
      if (lastNotUsedIndex <= allCount) {
        long long curVal = (1ll << (i + 1));
        if (noPow2[lastNotUsedIndex] > curVal) {
          ok = false;
          break;
        }
        long long q =
            min(allCount - (long long)lastNotUsedIndex + 1, curCnt[i]);
        curCnt[i] -= q;
        if (i - 1 >= 0) curCnt[i - 1] += curCnt[i];
        lastNotUsedIndex += q;
      } else {
        if (i - 1 >= 0) curCnt[i - 1] += curCnt[i];
      }
    }
    if (ok && lastNotUsedIndex > allCount) {
      answer.push_back(cntNumber);
    }
  }
  if (answer.size() == 0) {
    answer.push_back(-1);
  }
  for (int i = 0; i < answer.size(); ++i) {
    cout << answer[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  solveTask();
  return 0;
}
