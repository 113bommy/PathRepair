import collections

if __name__ == "__main__":

    n, q = list(map(int, input().split()))
    a = collections.deque(map(int, input().split()))
    maxn = max(a)

    res = list(range(n))
    cnt = 1
    while True:
        if a[0] == maxn:
            break

        res[cnt] = [a[0], a[1]]
        cnt += 1

        A = a.popleft()
        B = a.popleft()
        if A > B:
            a.appendleft(A)
            a.append(B)
        else:
            a.appendleft(B)
            a.append(A)

    for i in range(q):
        m = int(input())
        if m < cnt:
            print(res[m][0], res[m][1])
        else:
            print(maxn, a[(m - cnt) % (n - 1) + 1])

