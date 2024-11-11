n=int(input())
a=list(map(int,input().split()))
k,m=map(int, input().split())
print(sum(a[k-1:m-1]))