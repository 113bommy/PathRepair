import sys
input = sys.stdin.buffer.readline


def is_prime(x):
    if x == 2:
        return True
    if x == 1 or x % 2 == 0:
        return False
    for k in range(3, int(x ** 0.5) + 1, 2):
        if x % k == 0:
            return False
    return True


t = int(input())
ans = []

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    sum_ = sum(a)
    if not is_prime(sum_):
        ans.append([i + 1 for i in range(n)])
    else:
        for i in range(n):
            if a[i] % 2 == 1:
                res = [j + 1 for j in range(n)]
                res.remove(i + 1)
                ans.append(res)
                break

for res in ans:
    print(len(res))
    print(*res)