#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s1, s2, s3; cin >> s1 >> s2 >> s3;
  cout << (s1.back() == s2.front() %% s2.back() == s3.front() ? "YES" : "NO");
  return 0;
}