n = int(input())
A = [-int(x) for x in input().split()]
A.sort()
print(-A[n//2])