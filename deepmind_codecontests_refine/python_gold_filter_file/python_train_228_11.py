t = int(input())
a = [chr(ord('a') + i) for i in range(26)]
integer = [i for i in range(1,27)]
for _ in range(t):
    n,m = map(int,input().split())
    s = list(input())
    p = list(map(int,input().split()))
    p.sort()
    p.append(n)
    for i in range(len(s)):
        for j in range(len(integer)):
            if s[i] == a[j]:
                s[i] = integer[j]
    cnt = [0] * 26
    cnt_now = [0] * 26
    here = p[0]
    for i in range(0,here):
        cnt[s[i] - 1] += 1
        cnt_now[s[i] - 1] += 1
    for j in range(m):
        for i in range(26):
            cnt[i] += cnt_now[i]
        for i in range(here, p[j+1]):
            cnt_now[s[i]-1] += 1
            cnt[s[i]-1] += 1
            here = p[j+1]
    print(*cnt)
