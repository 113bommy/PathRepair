n = int(input())

for i in range(n):
    s = str(input())
    t = str(input())
    c = 0
    a = []
    for i in range(len(t)):
        k = t[i]
        l = i
        for i in range(len(s)):
            if k == s[i]:
                a.append(i+1)
    for i in range(len(a)-1):
        c += abs(a[i+1] - a[i])
    print(c)
