from sys import stdin, stdout

n, k = map(int, stdin.readline().split())
values = list(map(int, stdin.readline().split()))

sze = max(values)
used = [0 for i in range(sze + 1)]
challengers = [[] for i in range(n + 1)]

i = 0
cnt = 0
    
for i in range(n):
    if values[i] == k:
        cnt += 1
    elif used[values[i]] >= cnt:
        used[values[i]] += 1
        challengers[used[values[i]]].append(values[i])
    
for i in range(n, cnt - 1, -1):
    if len(challengers[i]):
        stdout.write(str(challengers[i][0]))
        break
else:
    stdout.write('-1')