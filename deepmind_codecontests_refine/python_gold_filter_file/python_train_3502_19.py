d = {}
n, m = map(int, input().split())
for _ in range(n):
        l = list(map(str, input().split()))
        d[l[1] + ";"] = l[0]
for _ in range(m):
        l = list(map(str, input().split()))
        print(l[0] + " " + l[1] + " #" + d[l[1]])