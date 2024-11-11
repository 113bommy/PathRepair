#include <bits/stdc++.h>
using namespace std;
string s;
set<int> stt;
bool flag1, flag2;
void print(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    if (i != v.size() - 1) {
      cout << v[i] << " ";
    } else {
      cout << v[i] << endl;
    }
  }
}
void solve1(int n, vector<int> v, set<int> st) {
  if (v.size() == n) {
    print(v);
    flag1 = false;
    return;
  }
  if (!flag1) {
    return;
  }
  int pos = v.size();
  if (pos < n - 1) {
    if (s[pos] == '>') {
      set<int>::iterator it = st.end();
      it--;
      int a = *(it);
      st.erase(it);
      v.push_back(a);
      solve1(n, v, st);
    } else {
      set<int>::iterator it = st.end();
      it--;
      it--;
      for (it; it != st.begin(); it--) {
        int aa = *it;
        if (pos == 0 || (s[pos - 1] == '<' && aa > v[v.size() - 1]) ||
            (s[pos - 1] == '>' && aa < v[v.size() - 1])) {
          vector<int> nowV = v;
          nowV.push_back(*it);
          st.erase(it);
          solve1(n, nowV, st);
          st.insert(aa);
          it = st.find(aa);
        }
      }
      int bb = *(st.begin());
      if (pos == 0 || (s[pos - 1] == '<' && bb > v[v.size() - 1]) ||
          (s[pos - 1] == '>' && bb < v[v.size() - 1])) {
        vector<int> nowV = v;
        nowV.push_back(*(st.begin()));
        st.erase(st.begin());
        solve1(n, nowV, st);
        st.insert(bb);
      }
    }
  } else {
    int a = *(st.begin());
    st.erase(a);
    v.push_back(a);
    solve1(n, v, st);
  }
}
void solve2(int n, vector<int> v, set<int> st) {
  if (v.size() == n) {
    print(v);
    flag2 = false;
    return;
  }
  if (!flag2) {
    return;
  }
  int pos = v.size();
  if (pos < n - 1) {
    if (s[pos] == '<') {
      set<int>::iterator it = st.begin();
      int a = *(it);
      st.erase(it);
      v.push_back(a);
      solve2(n, v, st);
    } else {
      set<int>::iterator it;
      it = st.begin();
      it++;
      for (it; it != st.end(); it++) {
        int aa = *it;
        if (pos == 0 || (s[pos - 1] == '>' && aa < v[v.size() - 1]) ||
            (s[pos - 1] == '<' && aa > v[v.size() - 1])) {
          vector<int> nowV = v;
          nowV.push_back(*it);
          st.erase(it);
          solve2(n, nowV, st);
          st.insert(aa);
          it = st.find(aa);
        }
      }
    }
  } else {
    int a = *(st.begin());
    st.erase(a);
    v.push_back(a);
    solve2(n, v, st);
  }
}
void fig1(int n) {
  vector<int> v;
  int num = n;
  int i = 0;
  while (i < n - 1) {
    if (s[i] == '>') {
      v.push_back(num);
      num--;
      i++;
    } else {
      int j = i + 1;
      while (j < n - 1 && s[j] == '<') {
        j++;
      }
      int lnum = j - i;
      for (int k = num - lnum; k <= num; k++) {
        v.push_back(k);
      }
      num = num - lnum - 1;
      i = j + 1;
    }
  }
  while (num > 0) {
    v.push_back(num);
    num--;
  }
  print(v);
}
void fig2(int n) {
  vector<int> v;
  int num = 1;
  int i = 1;
  while (i < n - 1) {
    if (s[i] == '<') {
      v.push_back(i);
      i++;
      num++;
    } else {
      int j = i + 1;
      while (j < n - 1 && s[j] == '>') {
        j++;
      }
      int hnum = j - i;
      for (int k = num + hnum; k >= num; k--) {
        v.push_back(k);
      }
      i = j + 1;
      num = num + hnum + 1;
    }
  }
  while (num <= n) {
    v.push_back(num);
    num++;
  }
  print(v);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n >> s;
    fig1(n);
    fig2(n);
  }
  return 0;
}
