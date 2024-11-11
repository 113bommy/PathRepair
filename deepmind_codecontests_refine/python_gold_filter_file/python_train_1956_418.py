N,K=map(int,input().split())
t=N%K
print(min(t,abs(t-K)))