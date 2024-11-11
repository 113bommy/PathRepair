def mp():
    return map(int, input().split())

n = int(input())
a = list(mp())
r = [abs(a[i] - a[i + 1]) for i in range(n - 1)]
if n != 1 and max(r) >= 2:
    print('NO')
else:
    print('YES')