#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> v;
  v.push_back("123");
  v.push_back("one");
  v.push_back("two");
  v.push_back("three");
  v.push_back("four");
  v.push_back("five");
  v.push_back("six");
  v.push_back("seven");
  v.push_back("eight");
  v.push_back("nine");
  v.push_back("ten");
  v.push_back("eleven");
  v.push_back("twelve");
  v.push_back("thirteen");
  v.push_back("fourteen");
  v.push_back("fifteen");
  v.push_back("sixteen");
  v.push_back("seventeen");
  v.push_back("eighteen");
  v.push_back("nineteen");
  v.push_back("twenty");
  v.push_back("thirty");
  v.push_back("forty");
  v.push_back("fifty");
  v.push_back("sixty");
  v.push_back("seventy");
  v.push_back("eighty");
  v.push_back("ninety");
  if (n <= 20)
    cout << v[n];
  else if (n % 10 != 0)
    cout << v[n / 10 + 18] << "-" << v[n % 10];
  else
    cout << v[n / 10 + 18];
}
