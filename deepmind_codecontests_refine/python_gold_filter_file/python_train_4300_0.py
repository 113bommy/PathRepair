from sys import stdin

t = int(stdin.readline())

for _ in range(t):
    L = [int(x) for x in stdin.readline().split(" ")]
    n, k, m = L[0], L[1], L[2]

    A = [int(x) for x in stdin.readline().split(" ")]

    if (n - m) % (k - 1) != 0:
        print("NO")
        continue

    works = False
    k = (k - 1) // 2
    count = 0
    for i in range(m):
        a = A[i]
        if a - i - 1 >= k and n - a - (m - 1 - i) >= k:
            works = True
            break

    if works:
        print("YES")
    else:
        print("NO")
