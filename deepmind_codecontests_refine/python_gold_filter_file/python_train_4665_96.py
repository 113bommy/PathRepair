n=int(input())
L=sorted(list(map(int,input().split())))
print(L[n//2]-L[n//2-1])