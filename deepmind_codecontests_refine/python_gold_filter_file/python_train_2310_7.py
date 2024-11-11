s = input().strip()

lowPrev = 'z'

good = [False for x in range(len(s))]

for k in range(len(s)):
    if s[k] > lowPrev:
        good[k] = True
    else:
        lowPrev = s[k]

for x in good:
    if x:
        print('Ann')
    else:
        print('Mike')
