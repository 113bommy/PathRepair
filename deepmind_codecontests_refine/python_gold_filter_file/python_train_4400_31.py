n = int(input()) #presents
p = list(map(int,input().split()))
q = list(p)
for i in range(n):
    x = p[i]-1
    for j in range(n):
        q[x] = i+1
print(*q)