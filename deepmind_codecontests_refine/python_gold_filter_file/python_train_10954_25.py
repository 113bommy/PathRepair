n=int(input())
x=[0]*(4*10**6+1)
bi=[*map(int,input().split())]
for i in range(n):
    x[bi[i]-i]+=bi[i]
print(max(x))