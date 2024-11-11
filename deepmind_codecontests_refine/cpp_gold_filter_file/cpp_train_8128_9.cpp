#include <bits/stdc++.h>
using namespace std;
int freq[26] = {0};
bool cmp(int x, int y) { return freq[x] < freq[y]; }
int main(int argc, char **argv) {
  string S;
  int K;
  cin >> S >> K;
  int N = S.length();
  for (int i = (0); i < (N); ++i) freq[S[i] - 'a']++;
  int ptr[26];
  for (int i = (0); i < (26); ++i) ptr[i] = i;
  for (int i = (0); i < (26); ++i)
    if (!freq[i]) freq[i] = 1 << 29;
  sort(ptr, ptr + 26, cmp);
  for (int i = (0); i < (26) && (K && freq[ptr[i]] != 1 << 29); ++i) {
    int j = min(K, freq[ptr[i]]);
    K -= j;
    freq[ptr[i]] -= j;
  }
  string t;
  int res = 0;
  for (int i = (0); i < (26); ++i)
    if (freq[i] > 0 && freq[i] < 1 << 29) res++;
  cout << res << endl;
  for (int i = (0); i < (N); ++i)
    if (freq[S[i] - 'a']) t = t + S[i], freq[S[i] - 'a']--;
  cout << t << endl;
  return 0;
}
