from math import ceil
def func():
    for i in range(n):
        if ceil(W/2) <= w[i] <= W:
            print(1)
            print(i+1)
            return
        else:
            if w[i] > W:
                w[i] = -1

    lst = list()
    total = 0
    for i in range(n):
        if w[i] == -1:
            continue
        lst.append(i+1)
        total += w[i]
        if total >= ceil(W/2):
            print(len(lst))
            print(*lst)
            return
    print(-1)


for _ in range(int(input())):
    n, W = map(int, input().split())
    w = list(map(int, input().split()))
    func()
