t = int(input())
for i in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = []
    avg = sum(a) // n
    if sum(a) % n != 0:
        print(-1)
        continue
    for i in range(1, n):
        ans.append([1, i + 1, (i + 1 - a[i] % (i + 1)) % (i + 1)])
        ans.append([i + 1, 1, (a[i] + i) // (i + 1)])
    for i in range(1, n):
        ans.append([1, i + 1, avg])
    print(len(ans))
    for i in ans:
        print(str(i[0]) + ' ' + str(i[1]) + ' ' + str(i[2]))
