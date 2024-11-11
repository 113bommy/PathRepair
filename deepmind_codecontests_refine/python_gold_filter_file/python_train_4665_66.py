N=int(input())
L=list(map(int,input().split()))
L=sorted(L)
print(L[N//2]-L[N//2-1])