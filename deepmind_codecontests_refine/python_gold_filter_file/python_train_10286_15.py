N = int(input())
*p, = map(int, input().split())

v = sum(1 for i,j in zip(range(1, N+1), p) if i!=j)
print("YES" if v<=2 else "NO")