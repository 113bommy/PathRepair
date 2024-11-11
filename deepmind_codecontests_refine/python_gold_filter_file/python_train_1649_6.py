n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
maxn=0
for i in range(n):
    maxn=max(maxn,sum(a[:i+1])+sum(b[i:]))
print(maxn)