n,k=map(int,input().split())
a=sorted(list(map(int,input().split())),reverse=True)
print(sum(a[0:k]))