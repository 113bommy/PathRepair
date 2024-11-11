
for _ in range(int(input())):
    n = int(input())
    if n // 2 % 2 == 1:
        print('NO')
    else:
        a = [2*i for i in range(1, n // 2 + 1)]
        b = [2*i - 1 for i in range(1, n // 2)]
        current = sum(b)
        b.append(sum(a) - current)
        print('YES')
        print(*(a + b))
