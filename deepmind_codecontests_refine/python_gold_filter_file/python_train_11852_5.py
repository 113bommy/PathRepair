from collections import deque


def solve(K):
    s = 1
    q = deque()
    q.append(s)
    dists = {}
    dists[s] = 1
    while len(q) > 0:
        n = q.pop()
        if n == 0:
            break
        m = (n*10)%K
        if m not in dists:
            dists[m] = dists[n]
            q.append(m)
        elif dists[m] > dists[n]:
            dists[m] = dists[n]
            q.append(m)
        if n % 10 != 9:
            m = (n+1)%K
            if m not in dists:
                dists[m] = dists[n] + 1
                q.appendleft(m)
            elif dists[m] > dists[n] + 1:
                dists[m] = dists[n] + 1
                q.appendleft(m)
    return dists[0]


def main():
    K = int(input())
    print(solve(K))


if __name__ == '__main__':
    main()
