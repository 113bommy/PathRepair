n = int(input())
s = []
for i in range(n):
    a, b = map(str, input().split())
    a = int(a)
    s.append((a, b))
ans = float('inf')
mina = ans
minb = mina
minc = minb
for i in s:
    if('A' in i[1] and mina > i[0]):
        mina = i[0]
    if('B' in i[1] and minb > i[0]):
        minb = i[0]
    if('C' in i[1] and minc > i[0]):
        minc = i[0]
ans = mina + minb + minc
for i in s:
    if(len(i[1]) == 2):
        if('A' in i[1] and 'B' in i[1] and minc + i[0] < ans):
            ans = minc + i[0]
        if('A' in i[1] and 'C' in i[1] and minb + i[0] < ans):
            ans = minb + i[0]
        if('C' in i[1] and 'B' in i[1] and mina + i[0] < ans):
            ans = mina + i[0]
    elif(len(i[1]) == 3):
        ans = min(ans, i[0])
if(ans == float('inf')):
    print(-1)
else:
    print(ans)