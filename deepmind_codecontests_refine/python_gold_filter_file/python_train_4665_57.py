N=int(input())
L=sorted(list(map(int,input().split())))
print(L[N//2]-L[N//2-1])