from collections import deque
hv, av, cv = [int(x) for x in input().split()]
hc, ac = [int(x) for x in input().split()]
q = deque()
q.append([hv, hc, []])
win = [1] * 20000
cc = 0
while len(q) != 0:
    seq = q.popleft()
    if seq[1] - av <= 0:
        if len(seq[2] + ['STRIKE']) < len(win):
            win = seq[2] + ['STRIKE']
    else:
        if seq[0] - ac > 0:
            q.append([seq[0] - ac, seq[1] - av, seq[2] + ['STRIKE']])
        else:
            q.append([seq[0] + cv - ac, seq[1], seq[2] + ['HEAL']])
print(len(win))
for i in win:
    print(i)