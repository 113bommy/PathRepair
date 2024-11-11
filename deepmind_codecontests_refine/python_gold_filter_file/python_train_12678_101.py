N,A,B=map(int,input().split())
print(int(N/(A+B))*A+min(A,N%(A+B)))