n=int(input())
d=list(map(int,input().split()))
d.sort()
e=d[n//2-1]
f=d[n//2]
print(f-e)
