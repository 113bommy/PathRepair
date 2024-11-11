n = int(input())
for i in range(n):
    s = input()
    ok = True
    for j in range(len(s) // 2):
        if (s[j] != s[len(s) - j - 1]):
            ok = False
            break
    if not ok:
        print(s)
    else:
        ok = False
        for j in range(1, len(s)):
            if s[j] != s[j - 1]:
                ok = True
                print(s[:j - 1] + s[j] + s[j - 1] + s[j + 1:])
                break
        if not ok:
            print(-1)