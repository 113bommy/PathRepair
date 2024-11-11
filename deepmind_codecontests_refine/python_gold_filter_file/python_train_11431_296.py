K,X=map(int,input().split())
print(*[X-K+1+i for i in range(K*2-1)])