t = int(input())
s = 'abcdefghijklomnpqrstuvwxyz'
for _ in range(t):
    n, a, b = map(int, input().split())
    print("".join([s[i%b] for i in range(n)]))
