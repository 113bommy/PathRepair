k = int(input())
for i in range(k):
    n = int(input())
    s = input()
    t = input()
    o = s + t
    a = [0] * 26
    for j in o:
        a[ord(j) - 97] += 1
    for j in a:
        if j % 2 == 1:
            print("No")
            break
    else:
        s = list(s)
        t = list(t)
        number = 0
        ans = []
        print("Yes")
        for j in range(n):
            if s[j] != t[j]:
                check = True
                for k in range(j + 1, n):
                    if t[k] == t[j]:
                        number += 1
                        ans.append([j + 1, k + 1])
                        t[k] = s[j]
                        s[j] = t[j]
                        check = False
                        break
                if check:
                    for k in range(j + 1, n):
                        if s[k] == t[j]:
                            number += 2
                            ans.append([j + 1, j + 1])
                            ans.append([k + 1, j + 1])
                            s[k] = s[j]
                            s[j] = t[j]
                            break
        print(number)
        for j in ans:
            print(*j)