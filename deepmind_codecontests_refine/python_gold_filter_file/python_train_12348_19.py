n = int(input())
A = [int(x) for x in input().split()]
A.sort()
if (A[n] == A[n - 1]): print("NO")
else: print("YES")
