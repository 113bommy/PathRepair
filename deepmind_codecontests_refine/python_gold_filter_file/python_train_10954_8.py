n=int(input())
b=list(map(int,input().split()))
p=[0]*((10**6))
for i in range(n):
    a=b[i]-i
    p[a]+=b[i]
print(max(p))