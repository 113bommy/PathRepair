N,X=map(int,input().split())
n=[int(input()) for i in range(N)]
print((X-sum(n))//min(n)+N)
