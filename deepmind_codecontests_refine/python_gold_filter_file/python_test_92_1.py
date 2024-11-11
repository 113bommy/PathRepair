t = int(input())
for _ in range(t):
    s = list(input())
    ab = 0
    ba = 0
    for i in range(1, len(s)):
        if s[i] == "a" and s[i - 1] == "b":
            ba += 1
        elif s[i] == "b" and s[i - 1] == "a":
            ab += 1
    if ab > ba:
        s[0] = "b"
    elif ba > ab:
        s[0] = "a"
    print(*s, sep="")
