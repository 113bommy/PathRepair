n,m,r=map(int,input().split())
s=min(map(int,input().split()))
b=max(map(int,input().split()))
print(max(r,b*(r//s)+r%s))
