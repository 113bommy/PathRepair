from functools import reduce
import operator
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    s = sum(arr)
    x = reduce(operator.xor, arr)
    added = 2
    while added <= s:
        added *= 2
    if x % 2:
        added += 1
    s += added
    x ^= added
    b = (x * 2 - s) // 2
    print(3)
    print(added, b, b)