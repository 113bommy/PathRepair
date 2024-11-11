t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    l = []
    counter = 1
    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            counter += 1
        else:
            l.append(counter)
            counter = 1
    if(counter != 0):
        l.append(counter)
    ans = 0
    x = []
    for i in range(len(l)-1, -1, -1):
        if(l[i] > 1):
            x.append([i, l[i]])
    for i in range(len(l)):
        if l[i] > 1:
            ans += 1
            x.pop()
        else:
            if len(x) > 0:
                x[-1][1] -= 1
                l[x[-1][0]] -= 1
                if x[-1][1] == 1:
                    x.pop()
                ans += 1
            else:
                ans += (len(l) - i + 1)//2
                break
    print(ans)