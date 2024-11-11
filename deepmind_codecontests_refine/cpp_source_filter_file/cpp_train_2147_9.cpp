#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int size(T x) {
  return x.size();
}
long long k[3], t[3];
int num_done[100005] = {};
queue<int> waiters[3];
set<pair<long long, int> > Q;
void try_putinto(int pid, int qnr, long long tijd) {
  if (!k[qnr]) {
    waiters[qnr].push(pid);
  } else {
    num_done[pid]++;
    k[qnr]--;
    Q.insert(make_pair(tijd + t[qnr], pid));
  }
}
void onefree(int qnr, long long tijd) {
  k[qnr]++;
  if (!waiters[qnr].empty()) {
    int pid_next = waiters[qnr].front();
    waiters[qnr].pop();
    try_putinto(pid_next, qnr, tijd);
  }
}
int main() {
  cin >> k[0] >> k[1] >> k[2];
  cin >> t[0] >> t[1] >> t[2];
  int n;
  cin >> n;
  vector<long long> arrival;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    arrival.push_back(tmp);
  }
  for (int i = 0; i < n; i++) {
    Q.insert(make_pair(arrival[i], i));
  }
  long long t_res = 0;
  while (!Q.empty()) {
    pair<int, int> pp = *Q.begin();
    long long tijd = pp.first;
    int pid = pp.second;
    Q.erase(Q.begin());
    if (num_done[pid] > 0) {
      onefree(num_done[pid] - 1, tijd);
    }
    if (num_done[pid] == 3) {
      t_res = max(t_res, tijd - arrival[pid]);
    } else {
      try_putinto(pid, num_done[pid], tijd);
    }
  }
  cout << t_res << endl;
}
