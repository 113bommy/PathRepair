t = int(input())

for w in range(t):
    n = int(input())
    s = list(input())

    if s[0] == '1' or s[-1] == '1':
        print(n * 2)
        continue

    indexOf1 = []
    bool = False

    for i in range(n):
        if s[i] == '1':
            indexOf1.append(i)
            bool = True

    if not bool:
        print(n)
        continue

    print(max((n - indexOf1[0]) * 2, (indexOf1[-1] + 1) * 2))