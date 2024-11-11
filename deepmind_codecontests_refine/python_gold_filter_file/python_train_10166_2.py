p, m = list(map(int, input().split()))
def ispos(k):
    am = []
    i = 2
    while (i * i <= k):
        if k % i == 0:
            k //= i
            am.append(i)
        else:
            i += 1
    if k != 1:
        am.append(k)
    for i in range(len(am)):
        if am[i] <= p:
            return False
    return True
for i in range(m, max(1, m - 1000), -1):
    if (ispos(i)):
        print(i)
        exit()
print(-1)