n = int(input())

def divisior(n):
    a = []
    i = 1
    while (i*i <= n):
        if n%i == 0:
            a.append(i)
            if (i*i != n): a.append(n//i)
        i += 1
    return a

ans = 0
a = divisior(n)

for x in a[1:]:
    tmp = n
    while (tmp%x == 0): tmp = tmp//x
    if (tmp%x == 1) : ans += 1

b = divisior(n-1)

ans = ans + len(b) -1

print(ans)


