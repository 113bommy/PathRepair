N = int(input())
A = list(map(int, input().split()))

L = [abs((N-1) - 2*i) for i in range(N)]

L.sort(); A.sort()

print(pow(2, (N-N%2)//2, 10**9+7) if L == A else 0)
