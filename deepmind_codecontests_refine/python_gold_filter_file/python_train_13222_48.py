def insertion_sort(a, n, g, cnt):
    for i in range(g, n):
        v, j = a[i], i - g
        while j >= 0 and a[j] > v:
            a[j + g] = a[j]
            j = j - g
            cnt += 1
        a[j + g] = v
    return cnt


n = int(input())
a = list(int(input()) for _ in range(n))

m, g, cnt = 0, n // 2 + 1, 0
glist = []

while g:
    m += 1
    glist.append(g)
    cnt = insertion_sort(a, n, g, cnt)
    g //= 2

print(m)
print(*glist)
print(cnt)
print('\n'.join(str(i) for i in a))