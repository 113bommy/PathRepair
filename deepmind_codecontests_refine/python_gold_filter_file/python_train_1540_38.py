n,m = map(int,input().split())
A = sum(list(map(int,input().split())))
print(max(n-A,-1))