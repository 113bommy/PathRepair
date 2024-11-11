n,v=list(map(int,input().split()))

y=[]

for j in range(n):
    h=list(map(int,input().split()))
    if v>min(h[1:]):
        y.append(j+1)

print(len(y))
b=list(set(y))
print(*b)

