n=int(input())
a=list(map(int,input().split()))
c,d=map(int,input().split())
print(sum(a[c-1:d-1]))