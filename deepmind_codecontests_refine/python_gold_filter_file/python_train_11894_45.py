def main():
    t = int(input())
    for i in range(t):
        solve()

def solve():
    n = int(input())
    if n <= 3:
        print(-1)
        return

    elif n == 4:
        print(*[3, 1, 4, 2])
    elif n == 5:
        print(*[5, 3, 1, 4, 2])

    elif n % 2 == 0:
        arr = [i for i in range(1, n, 2)]
        even = arr[-1] - 3
        arr.append(even)
        arr.append(arr[-1] + 4)
        arr += [i for i in range(n-2, 1, -2) if i != even]
        print(*arr)

    else:
        arr = [i for i in range(1, n+1, 2)]
        arr.append(arr[-1] - 3)
        arr.append(arr[-1] + 2)
        arr.append(arr[-1] - 4)
        arr += [j for j in range(arr[-1]-2, 1, -2)]
        print(*arr)

main()