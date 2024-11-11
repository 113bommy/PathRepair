n,k = map(int,input().split())
h = list(map(int,input().split()))

c = []
c.append(0)

for i in range(1,n):
    c.append(min([ c[max(i-j,0)] + abs(h[i] - h[max(i-j,0)]) for j in range(1,k+1) ]))

print(c[n-1])