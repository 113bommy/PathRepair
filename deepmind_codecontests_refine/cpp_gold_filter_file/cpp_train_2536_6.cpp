#include <bits/stdc++.h>
using namespace std;
const int MODULO = 1000000007;
const int INF = 100000000;
int main() {
  string s;
  cin >> s;
  bool http = false;
  if (s.find("http") == 0) http = true;
  int start_domain = http ? 4 : 3;
  int end_domain = (int)s.find("ru", start_domain + 1);
  string domain(s.begin() + start_domain, s.begin() + end_domain);
  string context(s.begin() + end_domain + 2, s.end());
  if (((int)(context).size()) != 0)
    printf("%s://%s.ru/%s", http ? "http" : "ftp", domain.c_str(),
           context.c_str());
  else
    printf("%s://%s.ru", http ? "http" : "ftp", domain.c_str());
  puts("");
  return 0;
}
