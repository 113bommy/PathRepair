from sys import stdin, stdout

def chardiff1(s1, s2):
    diff = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            diff += 1
    return diff <= 1

t = int(stdin.readline())
for _ in range(t):
    a, b = map(int, stdin.readline().split())
    s = []
    for _ in range(a):
        s.append(stdin.readline().strip())
    cand = [""]
    imp = False
    for i in range(b):
        ch = set(ss[i] for ss in s)
        new_cand = []
        for cs in cand:
            for c in ch:
                new_cand.append(cs+c)
        cand = new_cand
        if len(cand) > 1024:
            imp = True
            break
    if imp:
        print(-1)
        continue

    ans = None
    for c in cand:
        if all(chardiff1(c, ss) for ss in s):
            ans = c
            break
    if ans:
        print(ans)
    else:
        print(-1)
