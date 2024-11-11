
if __name__ == '__main__':
    n = int(input())
    ss = map(int, input().split())
    q = int(input())
    acc = 0
    sacc = [0]
    for s in ss:
        acc += s
        sacc.append(acc)

    for _ in range(q):
        l, r = map(int, input().split())
        print((sacc[r] - sacc[l - 1])//10)