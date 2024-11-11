n, p1, p2, p3, t1, t2 = list(map(int,input().strip().split(' ')))
intervals = [list(map(int,input().strip().split(' '))) for i in range(n)]
power = (intervals[n-1][1] - intervals[n-1][0]) * p1
for i in range(n-1):
  power += (intervals[i][1] - intervals[i][0] + min(intervals[i+1][0] - intervals[i][1],t1)) * p1 + min(max(intervals[i+1][0] - intervals[i][1] - t1,0),t2) * p2 + max(intervals[i+1][0] - intervals[i][1] - t1 - t2,0) * p3
print(power)