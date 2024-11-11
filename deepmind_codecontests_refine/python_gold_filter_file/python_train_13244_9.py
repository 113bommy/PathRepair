t = int(input())

for i in range(t):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    if a.count(x):
        print(1)
    else:
        q = max(a)
        print(max(2, int((x+q-1)/q)))