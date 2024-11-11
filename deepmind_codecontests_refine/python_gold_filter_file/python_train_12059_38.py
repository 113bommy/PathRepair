N,M=map(int,input().split())

if min(N,M)>1:
    print(M*N-2*(M+N-2))
elif N==1 and M==1:
    print(1)
else:
    print(max(M,N)-2)