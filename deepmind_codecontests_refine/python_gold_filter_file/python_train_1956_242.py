N,K=map(int,input().split())

print(min(abs(N%K),abs(N%K-K)))