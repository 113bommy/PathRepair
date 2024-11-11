n, k = map(int, input().split())
s = input()
if k == 1:
    t = []
    s = list(s)
    w = list(set(list(s)))
    for i in w:
        t += [s.count(i)]
    print(max(t))
    exit(0)
if n == k:
    s = list(s)
    if s.count(s[0]) == n:
        print(1)
    else:
        print(0)
    exit(0)
d = {0:0}
p = 1
i=0
while(i < n-1):
    if s[i] == s[i + 1]:
        p+=1
    else:
        p=1
    if p==k:
        if s[i] not in d:
            d[s[i]] = 1
        else:
            d[s[i]] += 1
        p=1
        i+=2
        #print(s[i])
    else:
        i+=1
    
print(max(d.values()))