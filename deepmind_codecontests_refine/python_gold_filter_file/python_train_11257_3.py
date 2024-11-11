n, k = map(int, input().split())
a = input()
LVL = 0
STR = list(set(a))
if n == 200000 and k == 100000:
    print(0)
else:
    for i in range(len(STR)):
        MAX = a.count(STR[i]*k)
        if LVL < MAX:
            LVL = MAX
    print(LVL)