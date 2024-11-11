t = int(input())
for i in range(t):
    a, b, c, d, k = map(int, input().split())
    pencils = a // c
    if pencils * c < a:
        pencils += 1
    if d * (k - pencils) >= b:
        print(pencils, k - pencils)
    else:
        print(-1)