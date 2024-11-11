H, W, N = map(int, input().split())
sr, sc = map(int, input().split())
S = input()
T = input()
l = 0
r = W+1
u = 0
d = H+1
flag = True
for s,t in zip(S[::-1],T[::-1]):
    if l+1==r or u+1==d:
        flag=False
        break
    if t == 'L':
        r = min(W+1, r+1)
    if t == 'R':
        l = max(0, l-1)
    if t == 'U':
        d = min(H+1, d+1)
    if t == 'D':
        u = max(0, u-1)
    if s == 'L':
        l += 1
    if s == 'R':
        r -= 1
    if s == 'U':
        u += 1
    if s == 'D':
        d -= 1
if not(l < sc < r and u < sr < d):
    flag = False
if flag:
    print('YES')
else:
    print('NO')