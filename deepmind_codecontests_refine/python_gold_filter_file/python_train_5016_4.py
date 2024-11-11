import sys

inp = [int(x) for x in sys.stdin.read().split()]

n = inp[0]
k = inp[1]
P = inp[2:n + 2]
Q = inp[n + 2: n + n + 2]

letters = 'abcdefghijklmnopqrstuvwxyz'

index = [0] * n
for i in range(n):
    P[i] -= 1
    Q[i] -= 1
    index[P[i]] = i

intervals = []
for i in range(n - 1):
    if index[Q[i]] > index[Q[i + 1]]:
        intervals.append((index[Q[i + 1]], index[Q[i]]))

intervals.sort()
color = [0] * n
cur_color = 0
interval_idx = 0
last = -1
for i in range(n):
    if last < i:
        cur_color += 1
    color[i] = cur_color
    while interval_idx < len(intervals) and intervals[interval_idx][0] == i:
        last = max(last, intervals[interval_idx][1])
        interval_idx += 1

if cur_color < k:
    print('NO')
else:
    ans = ['a'] * n
    for i in range(n):
        ans[P[i]] = letters[min(25, color[i] - 1)]
    print('YES')
    print(''.join(ans))
    
