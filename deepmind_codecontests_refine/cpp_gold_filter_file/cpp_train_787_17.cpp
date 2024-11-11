#include <bits/stdc++.h>
using namespace std;
long long n;
string s, t;
deque<char> deq, deq2;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> t;
  n = s.size();
  sort((s).begin(), (s).end()), sort((t).begin(), (t).end()),
      reverse((t).begin(), (t).end());
  for (long long(i) = (1); (i) <= ((n + 1) / 2); (i)++) deq.push_back(s[i - 1]);
  for (long long(i) = (1); (i) <= (n / 2); (i)++) deq2.push_back(t[i - 1]);
  string head, tail;
  for (long long(i) = (0); (i) <= (n - 1); (i)++) {
    if (i % 2 == 0) {
      if (deq.front() >= deq2.front())
        tail += deq.back(), deq.pop_back();
      else
        head += deq.front(), deq.pop_front();
    } else {
      if (deq.front() >= deq2.front())
        tail += deq2.back(), deq2.pop_back();
      else
        head += deq2.front(), deq2.pop_front();
    }
  }
  reverse((tail).begin(), (tail).end());
  cout << head + tail << endl;
  return 0;
}
