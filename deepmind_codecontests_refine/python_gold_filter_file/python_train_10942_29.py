t = int(input())
for k in range(t):
    s, a, b, c = map(int, input().split())
    x = s // c
    print(x // a * (a + b) + x % a)