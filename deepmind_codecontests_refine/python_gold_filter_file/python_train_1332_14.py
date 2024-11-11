S = input()

res = 0
p = ''
now = ''
for x in S:
    now += x
    if p != now:
        #print(now)
        res += 1
        p = now
        now = ''

print(res)
