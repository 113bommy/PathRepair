n = int(input())
arr = list(map(int, input().strip().split()))

mem = [[0 for i in range(n)] for i in range(n)]
for i in range(n):
    mem[i][i] = arr[i]

for diff in range(1, n):
    for L in range(n-diff):
        H = L+diff
        mem[L][H] = max(arr[L]-mem[L+1][H], arr[H]-mem[L][H-1])

print(mem[0][n-1])