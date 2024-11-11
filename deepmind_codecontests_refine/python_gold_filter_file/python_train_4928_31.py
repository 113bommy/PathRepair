n,a,b= map(int,input().split())
x = list(map(int,input().split()))
x.sort()
print(x[b]-x[b-1])
