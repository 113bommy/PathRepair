for _ in range(int(input())):
    s, x = list(map(int, input())), int(input())
    n = len(s)
    new = [1]*n
    for i in range(n):
        if s[i] == 0:
            if i >= x:new[i-x] = 0
            if i+x < n:new[i+x] = 0
    w = []
    for i in range(n):
        temp = 0
        if i >= x:
            if new[i-x] == 1:temp = 1
        if i+x < n:
            if new[i+x] == 1:temp = 1
        w.append(temp)
    if w != s:print(-1)
    else:print("".join(map(str, new)))