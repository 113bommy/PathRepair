#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int count_z = 0, count_nz = 1;
  vector<bool> primes(s.size() + 1);
  fill(primes.begin(), primes.end(), true);
  primes[0] = primes[1] = false;
  for (int i = 2; i <= s.size(); ++i)
    if (primes[i]) {
      if (2 * i <= s.size())
        count_z++;
      else
        count_nz++;
      for (int j = i * i; j <= s.size(); j += i) {
        if (primes[j] == true) {
          primes[j] = false;
          count_z++;
        }
      }
    }
  int counts[26];
  for (char x = 'a'; x <= 'z'; ++x)
    counts[x - 'a'] = count(s.begin(), s.end(), x);
  int* x = find_if(counts, counts + 26, bind2nd(greater<int>(), count_z));
  if (x != counts + 26) {
    stack<char> st;
    for (int* y = counts; y != counts + 26; ++y)
      if (y != x) {
        char c = 'a' + y - counts;
        for (int ctr = 0; ctr < *y; ++ctr) st.push(c);
      } else {
        char c = 'a' + y - counts;
        for (int ctr = count_z; ctr < *y; ++ctr) st.push(c);
      }
    assert(st.size() == count_nz);
    cout << "YES" << endl;
    cout << st.top();
    st.pop();
    for (int ctr = 2; ctr <= s.size(); ctr++)
      if (primes[ctr] && 2 * ctr > s.size()) {
        cout << st.top();
        st.pop();
      } else {
        char out = 'a' + x - counts;
        cout << out;
      }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}
