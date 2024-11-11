#include <bits/stdc++.h>
using namespace std;
static const unsigned int MOD = 1000000000 + 7;
struct Letter {
  struct Letter *next, *prev;
  unsigned int sum;
  void unlink() {
    next->prev = prev;
    prev->next = next;
  }
  void push_back(Letter& head) {
    next = &head;
    prev = head.prev;
    prev->next = this;
    head.prev = this;
  }
};
int main(int argc, const char* argv[]) {
  unsigned int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  Letter letters[26];
  for (int i = 0; i < k; i++) {
    letters[i].sum = 0;
    letters[i].next = &letters[(i + 1) % k];
    letters[i].prev = &letters[(i + k - 1) % k];
  }
  Letter head;
  head.next = &letters[0];
  head.prev = &letters[k - 1];
  letters[0].prev = &head;
  letters[k - 1].next = &head;
  unsigned int total = 1;
  for (typeof((s).end()) it = (s).begin(); it != (s).end(); ++it) {
    Letter& l = letters[*it - 'a'];
    unsigned int c = l.sum;
    l.sum = total;
    total = (2 * total - c + MOD) % MOD;
    l.unlink();
    l.push_back(head);
  }
  unsigned int sums[26];
  Letter* cur = head.next;
  for (int i = 0; i < k; i++, cur = cur->next) {
    sums[i] = cur->sum;
  }
  int c = 0;
  for (int j = 0; j < n; j++) {
    unsigned int t = sums[c];
    sums[c] = total;
    total = (2 * total - t + MOD) % MOD;
    c++;
    if (c == k) c = 0;
  }
  cout << total << endl;
  return 0;
}
