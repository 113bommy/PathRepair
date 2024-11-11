#include <bits/stdc++.h>
using namespace std;
pair<string, string> arr[100005];
string s1, s2;
int seq[100000];
int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2;
    if (s1 > s2) swap(s1, s2);
    arr[i] = make_pair(s1, s2);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &seq[i]);
    seq[i]--;
  }
  string prev = "";
  for (int i = 0; i < n; i++) {
    s1 = arr[seq[i]].first;
    s2 = arr[seq[i]].second;
    if (prev >= s1) {
      printf("NO\n");
      return 0;
    } else if (prev >= s2) {
      prev = s1;
    } else {
      prev = s2;
    }
  }
  printf("YES\n");
}
