def find(n, m, ss):
    s1 = ss[0]
    for i in range(m):
        for j in range(26):
            s1n = s1[:i] + [chr(97 + j)] + s1[i+1:]
            worked = True
            for s in ss:
                diffs = [a for a in range(m) if s[a] != s1n[a]]
                #if len(diffs) > 3:
                #    #print(''.join(s1n))
                #    print(-1); return
                if len(diffs) >= 2:
                    worked = False
                    break
            if worked:
                print(''.join(s1n))
                return
    print(-1)

t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    ss = []
    for j in range(n):
        ss.append(list(input()))
    find(n, m, ss)
