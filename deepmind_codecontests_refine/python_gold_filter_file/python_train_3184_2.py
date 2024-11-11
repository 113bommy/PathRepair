ts, tf, t = map(int, input().split())
n = int(input())
INF = int(10**18)
if n == 0:
    print(ts)
    quit()
a = list(map(int, input().split()))
i = 0
ans = -1
best = INF
end = ts
dif = 0

def checkans(curans, time):
    global ans, best
    # print(curans, end=" ")
    # print(time)
    if curans < best and time + max(curans,0) + t <= tf:
        ans = time
        best = curans


while i < n:
    dif = t
    pri = i - 1
    while i + 1 < n and a[i] == a[i + 1]:
        dif += t
        i += 1
    # check a[i] - 1
    if pri < 0 or a[pri] != a[i] - 1:
        checkans(end - (a[i] - 1), a[i] - 1)

    end += dif
    curans = end - a[i]
    checkans(end - a[i], a[i])
    i += 1
checkans(0, end)
print(ans)