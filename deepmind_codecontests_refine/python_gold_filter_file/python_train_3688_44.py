n=int(input())
c=list(map(int,input().split()))
a,b=map(int,input().split())
print(sum(c[a-1:b-1]))
