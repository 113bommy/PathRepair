q = int(input())
for i in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    print(s // n + (s % n != 0))