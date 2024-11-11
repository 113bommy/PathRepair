#include <bits/stdc++.h>
using namespace std;
int main() {
  int num_friend, pizza[102] = {0}, taxi[102] = {0}, girls[102] = {0};
  cin >> num_friend;
  int num_phones;
  string names, name[102];
  for (int i = 0; i < num_friend; i++) {
    cin >> num_phones >> names;
    name[i] = names;
    for (int x = 0; x < num_phones; x++) {
      char phones[102];
      stack<char> st;
      set<char> s;
      for (int y = 0; y < 8; y++) {
        cin >> phones[y];
        if (phones[y] == '-')
          continue;
        else {
          s.insert(phones[y]);
          if (y == 0)
            st.push(phones[y]);
          else {
            if (phones[y] < st.top()) st.push(phones[y]);
          }
        }
      }
      if (s.size() == 1) {
        taxi[i]++;
      } else if (st.size() == 6) {
        pizza[i]++;
      } else {
        girls[i]++;
      }
    }
  }
  int *maxp, *maxg, *maxt;
  maxp = max_element(pizza, pizza + num_friend);
  maxg = max_element(girls, girls + num_friend);
  maxt = max_element(taxi, taxi + num_friend);
  string pi, tax, gir;
  bool flag1 = false, flag2 = false, flag3 = false;
  for (int i = 0; i < num_friend; i++) {
    if (pizza[i] == *maxp) {
      if (flag1 && i != 0) pi += ", ";
      pi += name[i];
      flag1 = true;
    }
    if (taxi[i] == *maxt) {
      if (flag2 && i != 0) tax += ", ";
      tax += name[i];
      flag2 = true;
    }
    if (girls[i] == *maxg) {
      if (flag3 && i != 0) gir += ", ";
      gir += name[i];
      flag3 = true;
    }
  }
  cout << "If you want to call a taxi, you should call : " << tax << "."
       << endl;
  cout << "If you want to order a pizza, you should call : " << pi << "."
       << endl;
  cout << "If you want to go to a cafe with a wonderful girl, you should call: "
       << gir << "." << endl;
  return 0;
}
