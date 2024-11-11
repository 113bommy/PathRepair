A,B,C,D,E,F = map(int,input().split())
M = []
S = []

for a in range(1+F//100):
    for b in range(1+F//100):
        if 100*(a*A+b*B)<=F:
            M.append(100*(a*A+b*B))

for c in range(1+F//C):
    for d in range(1+F//D):
        if c*C+d*D<=F:
            S.append(c*C+d*D)

ans1 = 0
ans2 = 0
t = -1
for m in M:
    for s in S:
        if m==s==0:
            pass
        elif m+s<=F and s<=E*m//100 and t<(100*s)/(s+m):
            t = (100*s)/(s+m)
            ans1 = m+s
            ans2 = s

print(ans1, ans2)