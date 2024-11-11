n=int(input())
d=list(map(int,input().split()))
print(max(0,(n-d.count(min(d))-d.count(max(d)))))