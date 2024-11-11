n = int(input())
p = input()
q = input()
l = []
for i in range(len(p)):
    if p[i] == q[i]:
        pass
    else:
        l.append(i)

if len(l) == 1:
    print(1)
else:
    i = 0
    ans = 0
    while i < len(l) - 1:
        if l[i + 1] - l[i] > 1:
            ans += 1
            l[i] = -1
            i += 1
        else:
            if l[i + 1] - l[i] <= 1:
                if p[l[i]] != p[l[i + 1]]:
                    ans += l[i + 1] - l[i]
                    l[i] = -1
                    l[i + 1] = -1
                    i += 2
                else:
                    ans += 1
                    l[i] = -1
                    i += 1

    if len(l) == 0:
        print(0)
    else:
        if l[-1] != -1:
            print(ans + 1)
        else:
            print(ans)












