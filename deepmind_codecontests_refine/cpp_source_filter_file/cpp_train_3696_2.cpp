#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAX = 200001;
const int INF = 1e9;
enum EventType { Start = 0, End = 1 };
struct GasStation {
  GasStation() {}
  GasStation(int _t, int _x) : t(t), x(x) {}
  int t, x;
};
struct Segment {
  Segment(){};
  Segment(int _start, int _end, int _type)
      : start(_start), end(_end), type(_type){};
  int start, end, type;
  int ans1, ans2;
  int get_length() { return end - start; }
} segments[2 * MAX];
int nsegments = 0;
struct Event {
  Event() {}
  Event(int _x, EventType _event_type, int _gas_station_type)
      : x(_x), gas_station_type(_gas_station_type), event_type(_event_type) {}
  int x;
  EventType event_type;
  int gas_station_type;
} events[2 * MAX];
int nevents = 0;
int e, s, n, m;
GasStation gs[MAX];
int ngs = 0;
int main() {
  scanf("%d%d%d%d", &e, &s, &n, &m);
  for (size_t i = 0; i < n; i++) {
    GasStation st;
    scanf("%d%d", &st.t, &st.x);
    gs[i] = st;
    if (st.x < e) {
      events[nevents++] = Event(st.x, EventType::Start, st.t);
      events[nevents++] =
          Event(st.x + s >= e ? e : st.x + s, EventType::End, st.t);
    }
  }
  events[nevents++] = Event(e, EventType::End, 0);
  sort(events, events + nevents, [](const Event &a, const Event &b) -> bool {
    if (a.x == b.x) return a.event_type < b.event_type;
    return a.x < b.x;
  });
  int last_start[4];
  last_start[0] = last_start[1] = last_start[2] = last_start[3] = -INF;
  for (size_t i = 0; i < nevents; i++) {
    int start = i > 0 ? events[i - 1].x : -INF;
    int end = events[i].x;
    int type = events[i].x - last_start[3] <= s   ? 3
               : events[i].x - last_start[2] <= s ? 2
               : events[i].x - last_start[1] <= s ? 1
                                                  : 0;
    if (start < end) segments[nsegments++] = Segment(start, end, type);
    if (events[i].event_type == EventType::Start)
      last_start[events[i].gas_station_type] = events[i].x;
    else if (events[i].x - last_start[events[i].gas_station_type] == s)
      last_start[events[i].gas_station_type] = -INF;
  }
  int t1 = 0;
  int t2 = 0;
  for (int i = nsegments - 1; i >= 0; i--) {
    segments[i].ans1 = t1, segments[i].ans2 = t2;
    if (segments[i].type == 0) {
      t1 = t2 = INF;
    } else if (segments[i].type == 1) {
      t1 += t1 == INF ? 0 : segments[i].get_length();
    } else if (segments[i].type == 2) {
      t2 += t2 == INF ? 0 : segments[i].get_length();
    }
  }
  for (size_t i = 0; i < m; i++) {
    int f;
    scanf("%d", &f);
    f += s;
    int l = 0, r = nsegments - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      bool res = f <= segments[mid].end;
      if (res)
        r = mid - 1;
      else
        l = mid + 1;
    }
    Segment seg = segments[l];
    int ans1 = seg.ans1;
    int ans2 = seg.ans2;
    if (ans1 == INF || seg.type == 0 && seg.end > f)
      printf("-1 -1\n");
    else {
      ans1 += seg.type == 1 ? seg.end - f : 0;
      ans2 += seg.type == 2 ? seg.end - f : 0;
      printf("%d %d\n", ans1, ans2);
    }
  }
  return 0;
}
