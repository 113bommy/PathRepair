#include <bits/stdc++.h>
using namespace std;
using Time = int;
using UserID = int;
class SampleReader {
 private:
  istream& in;
  SampleReader(int n, int M, int T, istream& in) : n(n), M(M), T(T), in(in) {}

 public:
  const int n, M, T;
  static SampleReader of(istream& in) {
    int n, M, T;
    in >> n >> M >> T;
    return SampleReader(n, M, T, in);
  }
  Time nextTime() {
    int h, m, s;
    char sc;
    in >> h >> sc >> m >> sc >> s;
    return 3600 * h + 60 * m + s;
  }
};
class SampleHandler {
 private:
  vector<UserID> answer;
  int last_id;
  bool has_solution;

 public:
  static SampleHandler fromReader(SampleReader& sr) {
    SampleHandler sample_handler;
    vector<UserID>& answer = sample_handler.answer;
    UserID& prev_user_id = sample_handler.last_id;
    prev_user_id = 0;
    bool& conditions_fulfilled = sample_handler.has_solution;
    conditions_fulfilled = false;
    map<UserID, Time> time_map;
    for (int i = 0; i < sr.n; ++i) {
      Time cur_time = sr.nextTime();
      while (!time_map.empty() &&
             (cur_time - time_map.begin()->second) >= sr.T) {
        time_map.erase(time_map.begin());
      }
      if (time_map.size() + 1 <= sr.M) {
        if (time_map.size() + 1 == sr.M) {
          conditions_fulfilled = true;
        }
        time_map[++prev_user_id] = cur_time;
      } else {
        time_map.rbegin()->second = cur_time;
      }
      answer.push_back(prev_user_id);
    }
    return sample_handler;
  }
  void outputResult(ostream& out) {
    if (!has_solution) {
      out << "No solution\n";
      return;
    }
    out << last_id << endl;
    for (UserID user_id : answer) {
      out << user_id << "\n";
    }
  }
};
int main() {
  SampleReader sr = SampleReader::of(cin);
  SampleHandler sh = SampleHandler::fromReader(sr);
  sh.outputResult(cout);
}
