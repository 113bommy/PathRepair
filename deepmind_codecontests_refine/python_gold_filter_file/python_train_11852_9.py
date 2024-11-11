import collections
K = int(input())
Q = collections.deque([(1, 1)])
searched = set()
while True:
    n, d = Q.popleft()
    r = n % K
    if not r in searched:
        if r == 0:
            break
        else:
            searched.add(r)
            Q.append((n + 1, d + 1))
            Q.appendleft((n * 10 % K, d))
print(d)
# https://img.atcoder.jp/arc084/editorial.pdf
