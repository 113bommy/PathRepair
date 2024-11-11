n,m=map(int,input().split())
l=list(int(input()) for _ in range(n))
print(n+(m-sum(l))//min(l))