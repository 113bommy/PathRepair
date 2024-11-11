def lim(s):
    now = 0
    up, down = 0, 0
    for i in s:
        now += i
        up = max(up, now)
        down = min(down, now)
    return up, down
def f(a):
    return a[0] - a[1] + 1
def upg(s):
    t = lim(s)
    up, down = t[0], t[1]
    arr = [1, 1]
    now = 0
    for i in range(len(s) - 1):
        if now == up - 1 and s[i + 1] == 1 and arr[0] == 1:
            arr[0] = 0
            if f(lim(s[:(i + 1)] + [-1] + s[(i + 1):])) < f(t):
                return 1
        if now == down + 1 and s[i + 1] == -1 and arr[1] == 1:
            arr[1] = 0
            if f(lim(s[:(i + 1)] + [1] + s[(i + 1):])) < f(t):
                return 1
        now += s[i + 1]
    return 0


for q in range(int(input())):
    s = input()
    s1, s2 = [0], [0]
    for i in s:
        if i == 'W': s1.append(1)
        if i == 'S': s1.append(-1)
        if i == 'A': s2.append(1)
        if i == 'D': s2.append(-1)
    u1 = upg(s1)
    u2 = upg(s2)
    res1, res2 = f(lim(s1)), f(lim(s2))
    ans = min((res1 - u1) * res2, (res2 - u2) * res1)
    print(ans)