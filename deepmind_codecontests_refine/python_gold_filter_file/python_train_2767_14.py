from sys import stdin


n, el = stdin.read().split()
start = [0, 0, 0]
start[int(el)] = 1
n = int(n)
num_op = int(n/6)
num_r = n - num_op * 6
op = 6 if not num_r else num_r
while op:
    if not op % 2:
        start[1], start[2] = start[2], start[1]
    else:
        start[0], start[1] = start[1],  start[0]
    op -= 1
for i, el in enumerate(start):
    if el == 1:
        print(i)
        break
   