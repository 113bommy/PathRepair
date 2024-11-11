N,K=map(int,input().split())
m=N%K
print(min(abs(m-K),m))