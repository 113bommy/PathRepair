n = int(input())
A = list(map(int, input().split()))
print("YES" if all(abs(a - b) <= 1 for a, b in zip(A,A[1:])) else "NO")