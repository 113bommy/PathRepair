v1, v2, v3, vm = map(int, input().split())

if 2 * vm < v3 or 2 * v3 < vm or vm >= v2:
    print(-1)
else:
    print(2 * v1, 2 * v2, max(v3, vm), sep = "\n")