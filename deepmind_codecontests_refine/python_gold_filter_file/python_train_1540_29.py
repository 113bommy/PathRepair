n,m = map(int,input().split())

t = list(map(int,input().split()))

print(max(-1,n-sum(t)))