

INF = 10**9

A = [
    [0, 0,      0,      0],
    [0, INF,    3,      4],
    [0, 3,      INF,    INF],
    [0, 4,      INF,    INF]
]


n = int(input())

B = [int(x) for x in input().split()]

result = 0

for i in range(1, n):
    if B[i] == 2 and i > 1 and B[i - 2] == 3:
        result += 2
    else:
        result += A[B[i - 1]][B[i]]

print("Finite" if result < INF else "Infinite")
if result < INF:
    print(result)
