N,K,S=map(int,input().split())
if S==10**9:
    print(*([S]*K+[1]*max(0,N-K)))
else:
    print(*([S]*K+[10**9]*max(0,N-K)))