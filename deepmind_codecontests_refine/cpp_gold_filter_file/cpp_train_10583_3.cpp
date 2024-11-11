#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  long long l = v.size();
  for (long long i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
string subs[200];
int check[200];
string main_s;
string let;
void computeLPSArray(string pat, int M, int* lps) {
  int len = 0;
  lps[0] = 0;
  int i = 1;
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}
int KMPSearch(string pat, string txt) {
  int M = pat.size();
  int N = txt.size();
  int lps[M];
  computeLPSArray(pat, M, lps);
  int i = 0;
  int j = 0;
  while (i < N) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }
    if (j == M) {
      return i - j;
      j = lps[j - 1];
    } else if (i < N && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
  return -1;
}
bool compare(string s, string p) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  transform(p.begin(), p.end(), p.begin(), ::tolower);
  return s == p;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> subs[i];
  }
  cin >> main_s;
  cin >> let;
  int temp;
  string s1, s2;
  int temp1, temp2;
  for (int i = 0; i < n; i++) {
    s1 = main_s;
    s2 = subs[i];
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    temp = KMPSearch(s2, s1);
    if (temp != -1) {
      temp1 = subs[i].size();
      for (int j = temp; j < subs[i].size() + temp; j++) {
        check[j] = 1;
      }
      while (true) {
        s1 = main_s.substr(temp + 1, main_s.size());
        s2 = subs[i];
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        temp2 = KMPSearch(s2, s1);
        if (temp2 != -1) {
          for (int j = temp + temp2 + 1; j < subs[i].size() + temp + temp2 + 1;
               j++) {
            check[j] = 1;
          }
          temp = temp + temp2 + 1;
          temp1 += subs[i].size();
          if (temp + subs[i].size() > main_s.size()) {
            break;
          }
        } else {
          break;
        }
      }
    }
  }
  string ans = "";
  transform(let.begin(), let.end(), let.begin(), ::toupper);
  string up_let = let;
  transform(let.begin(), let.end(), let.begin(), ::tolower);
  string low_let = let;
  for (int i = 0; i < main_s.size(); i++) {
    if (check[i] == 1) {
      string temp = main_s.substr(i, 1);
      if (!compare(temp, let)) {
        if (main_s[i] >= 'a' and main_s[i] <= 'z') {
          ans += low_let;
        } else {
          ans += up_let;
        }
      } else if (compare(temp, let) and compare("a", let)) {
        if (main_s[i] >= 'a' and main_s[i] <= 'z') {
          ans += "b";
        } else {
          ans += "B";
        }
      } else if (compare(temp, let) and !compare("a", let)) {
        if (main_s[i] >= 'a' and main_s[i] <= 'z') {
          ans += "a";
        } else {
          ans += "A";
        }
      } else {
        ans += main_s[i];
      }
    } else {
      ans += main_s[i];
    }
  }
  cout << ans << "\n";
}
