N,K=map(int,input().split())

s=N%K
print(min(abs(s-K),s))