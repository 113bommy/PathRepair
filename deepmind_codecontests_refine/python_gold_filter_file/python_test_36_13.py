def solve():
    n = int(input())
    arr = [int(i) for i in input().split()]

    s = sum(arr)
    if errat[s] == 1:
        print(n)
        print(' '.join(str(i) for i in range(1, n + 1)))
        return

    for i in range(n):
        if errat[s - arr[i]] == 1:
            print(n - 1)
            print(' '.join(str(j) for j in range(1, n + 1) if (j - 1) != i))
            break


t = int(input())

errat = [0] * 201 * 100

for i in range(2, len(errat) // 2 + 1):
    if i == 1:
        continue

    current = i * 2
    while current < len(errat):
        errat[current] = 1
        current += i

for _ in range(t):
    solve()
