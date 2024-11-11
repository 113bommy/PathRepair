#include <bits/stdc++.h>
using namespace std;
int length;
char words[200005];
int zeus[200005], counter[200005];
void find_zeus() {
  int Left = 0, Right = 0;
  zeus[1] = length;
  for (int i = 2; i <= length; i++) {
    if (Right < i) {
      Left = Right = i;
      while (Right <= length && words[Right] == words[Right - Left + 1])
        Right++;
      zeus[i] = Right - Left, Right--;
    } else {
      int spot = i - Left + 1;
      if (zeus[spot] <= Right - i + 1)
        zeus[i] = zeus[spot];
      else {
        Left = i;
        while (Right <= length && words[Right] == words[Right - Left + 1])
          Right++;
        zeus[i] = Right - Left, Right--;
      }
    }
  }
}
void find_counter() {
  for (int i = 1; i <= length; i++) counter[zeus[i]]++;
  for (int i = length; i >= 1; i--) counter[i] += counter[i + 1];
}
int prefix_row[200005], good_prefix = 0;
void find_prefix_row() {
  for (int i = 1; i <= length; i++) {
    if (i + zeus[i] - 1 == length) prefix_row[++good_prefix] = zeus[i];
  }
}
void solve() {
  find_zeus();
  find_counter();
  find_prefix_row();
  sort(prefix_row + 1, prefix_row + good_prefix + 1);
  printf("%d\n", good_prefix);
  for (int i = 1; i <= good_prefix; i++)
    printf("%d %d\n", prefix_row[i], counter[prefix_row[i]]);
}
int main() {
  scanf("%s", words + 1);
  length = strlen(words + 1);
  solve();
}
