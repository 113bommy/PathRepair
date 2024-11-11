#include <bits/stdc++.h>
using namespace std;
struct intervals {
  int no;
  int lidz;
};
string aizpilda_v(const vector<intervals> &intervali, const string cur_virkne,
                  const int len, const int beigu_p) {
  int cur_punkti = beigu_p;
  string rez = cur_virkne;
  for (int i = len - 1; i > 0; --i) {
    if (cur_virkne[i] == 'W' && cur_punkti - 1 <= intervali.at(i - 1).lidz &&
        cur_punkti - 1 >= intervali.at(i - 1).no)
      --cur_punkti;
    else if (cur_virkne[i] == 'L' &&
             cur_punkti + 1 <= intervali.at(i - 1).lidz &&
             cur_punkti + 1 >= intervali.at(i - 1).no)
      ++cur_punkti;
    else if (cur_virkne[i] == '?') {
      if (cur_punkti == intervali.at(i - 1).lidz ||
          cur_punkti == intervali.at(i - 1).no)
        rez[i] = 'D';
      else if (cur_punkti - 1 <= intervali.at(i - 1).lidz &&
               cur_punkti - 1 >= intervali.at(i - 1).no) {
        rez[i] = 'W';
        --cur_punkti;
      } else if (cur_punkti + 1 <= intervali.at(i - 1).lidz &&
                 cur_punkti + 1 >= intervali.at(i - 1).no) {
        rez[i] = 'L';
        ++cur_punkti;
      } else {
        return "NO";
      }
    } else if (!(cur_virkne[i] == 'D' &&
                 (cur_punkti == intervali.at(i - 1).lidz ||
                  cur_punkti == intervali.at(i - 1).no))) {
      return "NO";
    }
  }
  if (cur_virkne[0] == 'W' && cur_punkti != 1)
    rez = "NO";
  else if (cur_virkne[0] == 'L' && cur_punkti != -1)
    rez = "NO";
  else if (cur_virkne[0] == 'D' && cur_punkti != 0)
    rez = "NO";
  else {
    if (cur_punkti == 0) {
      rez[0] = 'D';
    } else if (cur_punkti == 1)
      rez[0] = 'W';
    else if (cur_punkti == -1)
      rez[0] = 'L';
    else
      rez = "NO";
  }
  return rez;
}
string atrod_rez(const string virkne, const int len, const int limits) {
  vector<intervals> intervali(len);
  string rez;
  intervals cur_intervals;
  cur_intervals.no = 0;
  cur_intervals.lidz = 0;
  for (int i = 0; i < len - 1; ++i) {
    if (virkne[i] == 'W') {
      if (cur_intervals.lidz < limits - 1) ++cur_intervals.lidz;
      if (cur_intervals.no < cur_intervals.lidz) ++cur_intervals.no;
    } else if (virkne[i] == 'L') {
      if (cur_intervals.no > -limits + 1) --cur_intervals.no;
      if (cur_intervals.lidz > cur_intervals.no) --cur_intervals.lidz;
    } else if (virkne[i] == '?') {
      if (cur_intervals.no > -limits + 1) --cur_intervals.no;
      if (cur_intervals.lidz < limits - 1) ++cur_intervals.lidz;
    }
    intervali.at(i) = cur_intervals;
  }
  if (virkne[len - 1] == 'W') {
    ++cur_intervals.no;
    ++cur_intervals.lidz;
  } else if (virkne[len - 1] == 'L') {
    --cur_intervals.no;
    --cur_intervals.lidz;
  } else if (virkne[len - 1] == '?') {
    --cur_intervals.no;
    ++cur_intervals.lidz;
  } else
    return "NO";
  intervali.back() = cur_intervals;
  rez = "NO";
  if (virkne[len - 1] == 'W' && limits <= intervali.back().lidz &&
      limits >= intervali.back().no) {
    rez = aizpilda_v(intervali, virkne, len, limits);
  } else if (virkne[len - 1] == 'L' && -limits <= intervali.back().lidz &&
             -limits >= intervali.back().no) {
    rez = aizpilda_v(intervali, virkne, len, -limits);
  } else if (virkne[len - 1] == '?') {
    string temp_v = virkne;
    if (limits <= intervali.back().lidz && limits >= intervali.back().no) {
      temp_v[len - 1] = 'W';
      rez = aizpilda_v(intervali, temp_v, len, limits);
    }
    if (rez == "NO" && -limits <= intervali.back().lidz &&
        -limits >= intervali.back().no) {
      temp_v[len - 1] = 'L';
      rez = aizpilda_v(intervali, temp_v, len, -limits);
    }
  }
  return rez;
}
int main() {
  int len, limits;
  string virkne;
  cin >> len >> limits;
  cin >> virkne;
  cout << atrod_rez(virkne, len, limits) << endl;
  cout << endl;
  return 0;
}
