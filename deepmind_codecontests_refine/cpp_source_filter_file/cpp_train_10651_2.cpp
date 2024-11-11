#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s =
      "                                                                      ";
  int m;
  vector<string> sp, sg, st;
  int pmax = 0, gmax = 0, tmax = 0;
  string smaxp =
      "                                                                       ";
  string smaxg =
      "                                                                       ";
  string smaxt =
      "                                                                       ";
  string no = "                                                  ";
  int p = 0, g = 0, t = 0;
  for (int i = 0; i < n; i++) {
    cin >> m;
    cin >> s;
    for (int j = 0; j < m; j++) {
      cin >> no;
      if (no[7] == no[6] && no[4] == no[3] && no[0] == no[1] &&
          no[3] == no[6] && no[1] == no[6])
        t++;
      else if (no[1] < no[0] && no[3] < no[1] && no[4] < no[3] &&
               no[6] < no[4] && no[7] < no[6])
        p++;
      else
        g++;
    }
    if (p >= pmax) {
      if (p == pmax)
        sp.push_back(s);
      else {
        sp.clear();
        sp.push_back(s);
      }
      pmax = p;
    }
    if (g > gmax) {
      if (g == gmax)
        sg.push_back(s);
      else {
        sg.clear();
        sg.push_back(s);
      }
      gmax = g;
    }
    if (t >= tmax) {
      if (t == tmax)
        st.push_back(s);
      else {
        st.clear();
        st.push_back(s);
      }
      tmax = t;
    }
    g = 0;
    t = 0;
    p = 0;
  }
  int q1 = st.size();
  int q2 = sp.size();
  int q3 = sg.size();
  cout << "If you want to call a taxi, you should call: ";
  if (q1 != 0) {
    for (int i = 0; i < q1 - 1; i++) cout << st[i] << ", ";
    cout << st[q1 - 1] << ".";
    cout << endl;
  }
  if (q2 != 0) {
    cout << "If you want to order a pizza, you should call: ";
    for (int i = 0; i < q2 - 1; i++) cout << sp[i] << ", ";
    cout << sp[q2 - 1] << ".";
    cout << endl;
  }
  if (q3 != 0) {
    cout << "If you want to go to a cafe with a wonderful girl, you should "
            "call: ";
    for (int i = 0; i < q3 - 1; i++) cout << sg[i] << ", ";
    cout << sg[q3 - 1] << ".";
  }
  return 0;
}
