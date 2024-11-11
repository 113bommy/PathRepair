linesInt = int(input())
overflowLimit = (2**32)-1
baseX = 0
cacheMulti = [1]

for i in range(linesInt):
    xd = input()
    if "for" in xd:
        if (cacheMulti[-1]*int(xd.split()[-1])) < overflowLimit:
            cacheMulti.append(cacheMulti[-1]*int(xd.split()[-1]))
        else:
            cacheMulti.append(overflowLimit+1)
    elif "add" in xd:
        baseX += cacheMulti[-1]
    elif "end" in xd:
        cacheMulti.pop()

if baseX >= overflowLimit+1:
    print("OVERFLOW!!!")
else:
    print(baseX)