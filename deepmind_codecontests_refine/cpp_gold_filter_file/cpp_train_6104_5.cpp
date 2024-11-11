#include <bits/stdc++.h>
using namespace std;
int n, gen;
long long pos;
string f0 =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string formal = "What are you doing while sending \"";
string latter = "\"? Are you busy? Will you send \"";
string last = "\"?";
long long getLength(int n) {
  if (n > 55) {
    return LLONG_MAX - 1;
  }
  return pow(2, n) * (75 + 68) - 68;
}
void recursive(int n, long long pos) {
  if (n == 0) {
    printf("%c", f0[pos - 1]);
    return;
  }
  if (pos <= 34) {
    printf("%c", formal[pos - 1]);
    return;
  }
  pos -= 34;
  long long temp = getLength(n - 1);
  if (pos <= temp) {
    recursive(n - 1, pos);
    return;
  }
  pos -= temp;
  if (pos <= 32) {
    printf("%c", latter[pos - 1]);
    return;
  }
  pos -= 32;
  if (pos <= temp) {
    recursive(n - 1, pos);
    return;
  }
  pos -= temp;
  if (pos < 3) {
    printf("%c", last[pos - 1]);
    return;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %lld", &gen, &pos);
    long long length = 0;
    int j;
    if (getLength(gen) < pos) {
      printf(".");
      continue;
    }
    recursive(gen, pos);
  }
  return 0;
}
