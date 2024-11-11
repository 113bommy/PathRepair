n = int(input())
a = [int(k) for k in input().split()]
s = list(set(a))
s.sort()
dl = len(s)
if dl > 3:
    print(-1)
elif dl == 1:
    print(0)
elif dl == 2:
    if (s[1] - s[0]) % 2 == 0:
        print((s[1] - s[0]) // 2)
    else:
        print(s[1] - s[0])
else:
    if s[1] - s[0] == s[2] - s[1]:
        print(s[1] - s[0])
    else:
        print(-1)
