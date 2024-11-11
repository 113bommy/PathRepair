s, t = -10 ** 8, 10 ** 8
for i in range(int(input())):
    c, d = map(int, input().split())
    if d == 1:
        s = max(s, 1900)
    else:
        t = min(t, 1899)
   # print(s,t)
    if s > t:
        print('Impossible')
        exit()
    s, t = s + c, t + c
print('Infinity' if t > 5 * 10 ** 7 else t)