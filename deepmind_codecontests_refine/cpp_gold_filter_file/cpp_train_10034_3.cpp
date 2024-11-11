#include <bits/stdc++.h>
using namespace std;
const int MAXN = 16;
int n, cnt[MAXN];
vector<int> digits;
char IP[MAXN], outputs[64];
vector<string> answer;
vector<int> realIP;
void DFS(int depth, int pos, int length) {
  if (depth == 4) {
    if (pos == length) {
      sprintf(outputs, "%d.%d.%d.%d", realIP[0], realIP[1], realIP[2],
              realIP[3]);
      string tmpstr = outputs;
      answer.push_back(tmpstr);
    }
    return;
  }
  int v;
  v = IP[pos] - '0';
  realIP.push_back(v);
  DFS(depth + 1, pos + 1, length);
  realIP.pop_back();
  if (IP[pos] != '0' && pos + 1 < length) {
    v = (IP[pos] - '0') * 10 + (IP[pos + 1] - '0');
    realIP.push_back(v);
    DFS(depth + 1, pos + 2, length);
    realIP.pop_back();
  }
  if (IP[pos] != '0' && pos + 2 < length) {
    v = (IP[pos] - '0') * 100 + (IP[pos + 1] - '0') * 10 + (IP[pos + 2] - '0');
    if (0 <= v && v < 256) {
      realIP.push_back(v);
      DFS(depth + 1, pos + 3, length);
      realIP.pop_back();
    }
  }
}
int N;
void generate(int depth, int length) {
  if (depth == (length + 1) / 2) {
    for (int i = (0); i < (length); i++) {
      IP[length - i - 1] = IP[i];
    }
    IP[length] = '\0';
    if (N == n) {
      DFS(0, 0, length);
    }
    return;
  }
  for (typeof((digits).begin()) it = (digits).begin(); it != (digits).end();
       it++) {
    IP[depth] = *it + '0';
    if (!cnt[*it]) {
      N++;
    }
    cnt[*it]++;
    generate(depth + 1, length);
    cnt[*it]--;
    if (!cnt[*it]) {
      N--;
    }
  }
}
int main() {
  scanf("%d", &n);
  digits = vector<int>(n);
  for (int i = (0); i < (n); i++) {
    scanf("%d", &digits[i]);
  }
  for (int length = (4); length < (13); length++) {
    N = 0;
    memset(cnt, 0, sizeof(cnt));
    generate(0, length);
  }
  printf("%d\n", ((int)(answer).size()));
  for (typeof((answer).begin()) it = (answer).begin(); it != (answer).end();
       it++) {
    printf("%s\n", it->c_str());
  }
  return 0;
}
