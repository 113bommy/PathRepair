#include <bits/stdc++.h>
using namespace std;
class grav {
 private:
  char det;
  int n = 0;
  vector<vector<int> > gr;

 public:
  grav(string type) {
    this->n = 0;
    if (type == "lr") {
      this->det = 1;
    } else if (type == "ly") {
      this->det = 2;
    }
  }
  grav(string type, int a) {
    this->n = a;
    this->det = 0;
    for (int i = 0; i < this->n; i++) {
      this->gr.push_back(vector<int>());
      for (int j = 1; j < this->n; j++) {
        this->gr[i].push_back(0);
      }
    }
  }
  void rpush(int a, int b) {
    --a;
    --b;
    if (this->det == 0) {
      this->gr[a][b] = 1;
      this->gr[b][a] = 1;
    }
    if (this->r(a + 1, b + 1)) {
      return;
    }
    if (this->det == 1) {
      if (a + 1 > this->n) {
        this->n = a + 1;
      }
      if (b + 1 > this->n) {
        this->n = b + 1;
      }
      this->gr.push_back(vector<int>());
      this->gr[this->gr.size() - 1].push_back(a);
      this->gr[this->gr.size() - 1].push_back(b);
    }
    if (this->det == 2) {
      if (a + 1 > this->gr.size()) {
        for (int i = this->gr.size(); i < a + 1; i++) {
          this->gr.push_back(vector<int>());
        }
        this->n = a + 1;
      }
      this->gr[a].push_back(b);
      if (b + 1 > this->gr.size()) {
        for (int i = this->gr.size(); i < b + 1; i++) {
          this->gr.push_back(vector<int>());
        }
        this->n = b + 1;
      }
      this->gr[b].push_back(a);
    }
  }
  int size_info() { return this->n; }
  bool r(int a, int b) {
    --a;
    --b;
    if (this->det == 0) {
      return (this->gr[a][b]);
    }
    if (this->det == 1) {
      for (int i = 0; i < this->gr.size(); i++) {
        if ((this->gr[i][0] == a && this->gr[i][1] == b) ||
            (this->gr[i][0] == b && this->gr[i][1] == a)) {
          return 1;
        }
      }
      return 0;
    }
    if (this->det == 2) {
      if (a + 1 > this->gr.size()) {
        return 0;
      }
      for (int i = 0; i < this->gr[a].size(); i++) {
        if (this->gr[a][i] == b) {
          return 1;
        }
      }
      return 0;
    }
  }
  void rdel(int a, int b) {
    --a;
    --b;
    if (this->det == 0) {
      this->gr[a][b] = 0;
      this->gr[b][a] = 0;
    }
    if (!this->r(a + 1, b + 1)) {
      return;
    }
    if (this->det == 1) {
      for (int i = 0; i < this->gr.size(); i++) {
        if ((this->gr[i][0] == a && this->gr[i][1] == b) ||
            (this->gr[i][0] == b && this->gr[i][1] == a)) {
          this->gr.erase(this->gr.begin() + i);
          return;
        }
      }
    }
    if (this->det == 2) {
      for (int i = 0; i < this->gr[a].size(); i++) {
        if (this->gr[a][i] == b) {
          this->gr[a].erase(this->gr[a].begin() + i);
          break;
        }
      }
      for (int i = 0; i < this->gr[b].size(); i++) {
        if (this->gr[b][i] == a) {
          this->gr[b].erase(this->gr[b].begin() + i);
          return;
        }
      }
    }
  }
  void dfs(int s) {
    s--;
    stack<int> st;
    vector<bool> used(n, 0);
    st.push(s);
    used[s] = 1;
    if (det == 0) {
    }
    if (det == 1) {
    }
    if (det == 2) {
      while (!st.empty()) {
        s = st.top();
        bool l = 0;
        for (int i = 0; i < gr[s].size(); i++) {
          if (!used[gr[s][i]]) {
            used[gr[s][i]] = 1;
            st.push(gr[s][i]);
            l = 1;
            break;
          }
        }
        if (l) {
          continue;
        }
        st.pop();
      }
    }
  }
  void bfs(int s) {
    s--;
    queue<int> q;
    vector<bool> used(n, 0);
    q.push(s);
    used[s] = 1;
    if (det == 0) {
    }
    if (det == 1) {
    }
    if (det == 2) {
      while (!q.empty()) {
        s = q.front();
        q.pop();
        for (int i = 0; i < gr[s].size(); i++) {
          if (!used[gr[s][i]]) {
            used[gr[s][i]] = 1;
            q.push(gr[s][i]);
          }
        }
      }
    }
  }
};
long long a[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (; t >= 1; t--) {
    long long n, k = 0, sum = 0;
    string s;
    bool l = 0;
    cin >> n;
    vector<int> f(n);
    int ch = 0;
    for (int i = 0; i < n; i++) {
      cin >> f[i];
      sum += f[i];
      if (f[i] >= 2) {
        ch++;
      }
      if (k < f[i]) {
        k = f[i];
      }
    }
    if (n == 1) {
      cout << "T" << endl;
      continue;
    }
    if (n == 2 && abs(f[0] - f[1]) != 0) {
      cout << "T" << endl;
      continue;
    }
    if (n == 2 && abs(f[0] - f[1]) == 0) {
      cout << "HL" << endl;
      continue;
    }
    if (k >= sum / 2 + (sum % 2 != 0)) {
      cout << "T" << endl;
      continue;
    } else {
      if (sum % 2 == 0) {
        cout << "HL" << endl;
        continue;
      }
      if (sum % 2 != 0) {
        cout << "T" << endl;
        continue;
      }
    }
  }
}
