import sys
input = sys.stdin.readline
ins = lambda: input().rstrip()
ini = lambda: int(input())
inm = lambda: map(int, input().split())
inl = lambda: list(map(int, input().split()))

ans = []
t = ini()
for _ in range(t):
    n, m = inm()
    count = 0
    for i in range(n):
        s = ins()
        if i == n-1:
            count += s.count("D")
            break
        if s[-1] == "R":
            count += 1
    ans.append(count)
print('\n'.join(map(str, ans)))