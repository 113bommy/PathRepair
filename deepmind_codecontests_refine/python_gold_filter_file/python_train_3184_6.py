import bisect
import sys


ts, tf, T = [int(x) for x in input().split()]
N = int(input())
if N == 0:
    print(ts)
    sys.exit()
Ts = [int(x) for x in input().strip().split()]

# f = open('test.B.in.3', 'r')
# ts, tf, T = [int(x) for x in f.readline().split()]
# N = int(f.readline())
# Ts = [int(x) for x in f.readline().strip().split()]

check_times = sorted(set([x - 1 for x in Ts + [Ts[-1] + 2]
                          if x - 1 >= 0] + [ts]))

best_waiting_time, best_time = float('inf'), -1
last_waiting = None

all_times = []

for t in check_times:
    idx = bisect.bisect_right(Ts, t)

    if t < ts:
        # Number of people who have come before will be served first
        wt_time = (ts - t) + idx * T
    else:
        if last_waiting is not None:
            last_idx = last_waiting['idx']
            last_time = last_waiting['time']
            last_waiting_time = last_waiting['wt_time']
            wt_time = max(last_waiting_time + (idx - last_idx) * T  - (t - last_time), 0)
        else:
            wt_time = idx * T

    if wt_time < best_waiting_time and t + wt_time <= tf - T:
        best_waiting_time = wt_time
        best_time = t

    last_waiting = {
        'idx': idx,
        'time': t,
        'wt_time': wt_time
    }
    all_times.append(last_waiting)

tail_end = last_waiting['time'] + last_waiting['wt_time']
if tail_end <= tf - T and best_waiting_time > 0:
    best_waiting_time = 0
    best_time = tail_end

# print(sorted(waiting_times, key=lambda x: x['wt_time'])[0])
print(best_time)
