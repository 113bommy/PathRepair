n = int(input())
tree = list(map(int, input().split()))

for i in range(n) :
    s = 'node ' + str(i + 1) + ': key = ' + str(tree[i])
    if (i > 0) & (i % 2 == 0) :
        s += ', parent key = ' + str(tree[i // 2 - 1])
    elif (i > 0) & (i % 2 == 1):
        s += ', parent key = ' + str(tree[i // 2])

    if i * 2 + 2 < n :
        s += ', left key = ' + str(tree[i * 2 + 1]) + ', right key = ' + str(tree[i * 2 + 2])
    elif i * 2 + 1 < n :
        s += ', left key = ' + str(tree[i * 2 + 1])

    print(s, ', ', sep = '')

