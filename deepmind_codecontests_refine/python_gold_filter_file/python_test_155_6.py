from collections import defaultdict
inum = lambda: int(input())
imap = lambda: map(int,input().split())
ilist = lambda: list(map(int, input().split()))
for t in range(inum()):
    n = inum()
    arr = ilist()
    w = input()
    res = [-1 for i in range(n)]
    cnt, one, zero = 1, [], []
    for i in range(n):
        if w[i] == '1':
            one.append(arr[i])
        else:
            zero.append(arr[i])
    # print(one, zero)
    one, zero, = sorted(one), sorted(zero)
    hp = defaultdict(int)
    for i in zero:
        hp[i] = cnt
        cnt += 1
    for i in one:
        hp[i] = cnt
        cnt += 1
    for i in range(n):
        res[i] = hp[arr[i]]
    print(*res)