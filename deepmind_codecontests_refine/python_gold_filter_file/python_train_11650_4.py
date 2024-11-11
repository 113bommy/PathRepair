while True:
    n = int(input())
    if n == 0:
        break
    converter = {}
    for _ in range(n):
        k, v = input().split()
        converter[k] = v

    m = int(input())
    ans = []
    for _ in range(m):
        v = input().strip()
        try:
            ans.append(converter[v])
        except:
            ans.append(v)

    print("".join(ans))

