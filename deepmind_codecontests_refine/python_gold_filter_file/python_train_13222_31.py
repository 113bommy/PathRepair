#coding:utf-8
#1_2_D
def insertionSort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v

def shellSort(A, n):
    G = [1]
    while True:
        g = 3*G[0] + 1
        if g > n:
            break
        G.insert(0, g)
    m = len(G)
    for i in range(m):
        insertionSort(A, n, G[i])
    return [m, G]

n = int(input())
A = [int(input()) for i in range(n)]
cnt = 0
m, G = shellSort(A, n)
print(m)
print(" ".join(map(str, G)))
print(cnt)
print("\n".join(map(str, A)))