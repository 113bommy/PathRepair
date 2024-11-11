N=int(input())
W=[int(i) for i in input().split()]
print(min([abs(sum(W[:i])-sum(W[i:])) for i in range(N)]))
