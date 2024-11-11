#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  if (a[1] == '>') {
    m[a[0]]++;
    m[a[2]]--;
  } else {
    m[a[0]]--;
    m[a[2]]++;
  }
  if (b[1] == '>') {
    m[b[0]]++;
    m[b[2]]--;
  } else {
    m[b[0]]--;
    m[b[2]]++;
  }
  if (c[1] == '>') {
    m[c[0]]++;
    m[c[2]]--;
  } else {
    m[c[0]]--;
    m[c[2]]++;
  }
  if (m['A'] == m['B'] || m['B'] == m['C'] || m['A'] == m['C'])
    cout << "Impossible";
  else {
    if (m['A'] < m['B'] && m['A'] < m['C']) {
      cout << "A";
    } else if (m['B'] < m['A'] && m['B'] < m['C']) {
      cout << "B";
    } else if (m['C'] < m['B'] && m['A'] > m['C']) {
      cout << "C";
    }
    if ((m['A'] < m['B'] && m['A'] > m['C'])) {
      cout << "A";
    } else if ((m['B'] < m['A'] && m['B'] > m['C'])) {
      cout << "B";
    } else if ((m['C'] < m['B'] && m['C'] > m['A'])) {
      cout << "C";
    }
    if (m['C'] > m['B'] && m['C'] < m['A']) cout << "C";
    if (m['B'] > m['A'] && m['B'] < m['C']) cout << "B";
    if (m['A'] > m['B'] && m['A'] < m['C']) cout << "A";
    if (m['A'] > m['B'] && m['A'] > m['C']) {
      cout << "A";
    } else if (m['B'] > m['A'] && m['B'] > m['C']) {
      cout << "B";
    } else if (m['C'] > m['B'] && m['A'] < m['C']) {
      cout << "C";
    }
  }
}
