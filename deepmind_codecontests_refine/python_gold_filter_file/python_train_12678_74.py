N,A,B=map(int,input().split())
print(A*(N//(A+B))+min(A,N%(A+B)))