n,m=map(int,input().split())
a=list(int(input())for _ in range(n))
print(n+(m-sum(a))//min(a))