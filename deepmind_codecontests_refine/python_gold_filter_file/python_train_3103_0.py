N = int(input())
L = list(map(int, input().split()))
A = [abs(sum(L[:i])-sum(L[i:]))for i in range(1,N)]
print(min(A))