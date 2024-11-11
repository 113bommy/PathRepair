n = int(input())
for i1 in range(n):
    alf = input()
    s = input()
    d = {}
    for j in range(26):
        d[alf[j]] = j+1
    k = 0
    for i in range(1, len(s)):
        k += abs(d[s[i]] - d[s[i - 1]])
    print(k)