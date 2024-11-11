#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    string second;
    cin >> second;
    int t_g = 0, m_g = 0;
    vector<pair<char, int> > v;
    for (int i = 0; i < n; i++) {
      if (second[i] == 'G') {
        int c = 1;
        int j = i + 1;
        for (j; j < n; j++) {
          if (second[j] != 'G') break;
          c++;
        }
        v.push_back(make_pair('G', c));
        t_g += c;
        m_g = max(m_g, c);
        i = j - 1;
      } else {
        int c = 1;
        int j = i + 1;
        for (j; j < n; j++) {
          if (second[j] != 'S') break;
          c++;
        }
        v.push_back(make_pair('S', c));
        i = j - 1;
      }
    }
    if (m_g < t_g) m_g++;
    for (int i = 0; i < v.size(); i++) {
      if (i == 0 && v[i].first == 'S' && v[i].second == 1) {
        if (v[i + 1].second < t_g) m_g = max(m_g, v[i + 1].second + 1);
      } else if (i == v.size() - 1 && v[i].first == 'S' && v[i].second == 1) {
        if (v[i - 1].second < t_g) m_g = max(m_g, v[i - 1].second + 1);
      } else if (v[i].first == 'S' && v[i].second == 1) {
        if (v[i - 1].second + v[i + 1].second < t_g)
          m_g = max(m_g, v[i - 1].second + v[i + 1].second + 1);
        else
          m_g = max(m_g, v[i - 1].second + v[i + 1].second);
      }
    }
    cout << m_g;
  }
  return 0;
}
