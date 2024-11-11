def insertionSort(A, n, g):
    global cnt
    for i in range(g, n):
        v, j = A[i], i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j = j - g
            cnt += 1
        A[j + g] = v

# shellSort
cnt = 0
n = int(input())
G = [(3 ** i - 1) // 2 for i in range(11, 0, -1) if (3 ** i - 1) // 2 <= n]
m = len(G)
A = [int(input()) for _ in range(n)]
for i in range(m):
    insertionSort(A, n, G[i])
print(m)
print(" ".join(list(map(str, G))))
print(cnt)
for i in range(n):
    print(A[i])