N,K=map(int,input().split())
A=N%K
print(min(A,abs(A-K)))