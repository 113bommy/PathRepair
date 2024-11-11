n=int(input())
L=list(map(int,input().split()))
print(min([abs(sum(L[:t])-sum(L[t:])) for t in range(n)]))