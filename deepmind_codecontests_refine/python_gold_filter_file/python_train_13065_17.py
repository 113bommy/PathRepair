n,m = map(int, input().split())
f = [list(map(int, input().split())) for _ in range(n)]
c = 0
s = len(f[0])//m
for i in f:
    for j in range(s*m):
        if sum(i[j*s:(j+1)*s]) >= 1: 
            c+=1
print(c)
