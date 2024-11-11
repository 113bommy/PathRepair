counter = int(input())

for i in range(counter):
    a, n = map(int, input().split())

    k = bin(n)
    k = str(k)
    lis = list(k)
    del(lis[0])
    del(lis[0])
    leng = len(lis)
    op = 0
    for i in range(leng):
        if lis[leng - i -1] == '1':
            op += a**i
    print(int(op%(int(1e9 + 7))))