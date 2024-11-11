# input
n, m = map(int, input().rstrip().split())
n_array, m_array = list(map(int, input().rstrip().split())),list(map(int, input().rstrip().split()))
a, b = 0,0
while (a<n) & (b<m):
    if n_array[a] <= m_array[b]:
        a += 1
    b += 1
print(n-a)