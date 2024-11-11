H,W,N = map(int,input().split())
sr, sc = map(int,input().split())
S = input()
T = input()
L = sc-1
R = W-sc
U = sr-1
D = H-sr
for s, t in zip(S,T):
    if s == 'L':
        L -= 1
    elif s == 'R':
        R -= 1
    elif s == 'U':
        U -= 1
    elif s == 'D':
        D -= 1
    if min(L,R,U,D) < 0:
        print('NO')
        quit()
    if t == 'L' and R < W-1:
        R += 1
    elif t == 'R' and L < W-1:
        L += 1
    elif t == 'U' and D < H-1:
        D += 1
    elif t == 'D' and U < H-1:
        U += 1
print('YES')