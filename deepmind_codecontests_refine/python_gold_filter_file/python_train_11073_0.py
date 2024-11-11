n = int(input())
j = []
if n <= 2:
    print(-1)
else:
    for i in reversed(range(1, n+1)):
        j.append(i)
    print(' '.join(map(str, j)))