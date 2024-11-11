#include <bits/stdc++.h>
using namespace std;
vector<string> ret1, ret2;
char ans[1005];
vector<string> ask(int l, int r) {
  vector<string> temp;
  cout << "? " << l << " " << r << endl;
  int len = r - l + 1;
  len = len * (len + 1) / 2;
  for (int i = 0; i < len; i++) {
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    temp.push_back(str);
  }
  return temp;
}
int book[150];
map<string, int> mp;
int temp[130];
void select(vector<string> a, vector<string> b, int num) {
  mp.clear();
  for (int i = 0; i < b.size(); i++) {
    if (b[i].length() == num) mp[b[i]]++;
  }
  string str;
  for (int i = 0; i < a.size(); i++) {
    if (a[i].length() != num) continue;
    if (mp[a[i]] >= 1) {
      mp[a[i]]--;
      continue;
    }
    str = a[i];
    break;
  }
  memset(temp, 0, sizeof temp);
  for (int i = 'a'; i <= 'z'; i++) temp[i] = 0;
  for (int i = 0; i < str.length(); i++) temp[(int)str[i]]++;
  for (int i = 'a'; i <= 'z'; i++) {
    if (temp[i] > book[i]) {
      ans[num] = i;
      book[i]++;
      break;
    }
  }
}
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "? " << 1 << " " << 1 << endl;
    string str;
    cin >> str;
    cout << "! " << str << endl;
    return 0;
  }
  ret1 = ask(1, n);
  ret2 = ask(2, n);
  for (int len = 1; len <= n - 1; len++) {
    select(ret1, ret2, len);
  }
  string temp;
  cout << "? " << n << " " << n << endl;
  cin >> temp;
  ans[n] = temp[0];
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  puts("");
  return 0;
}
