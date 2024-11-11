import io,os
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
s = input()
n = len(s)
err = 0
f = []
l = [set(), set()]
cnt = 0
par = 0
for i in range(n):
    if(s[i] == "0"):
        if(len(l[0]) == 0):
            l[1].add(cnt)
            cnt+=1
            f.append([])
            f[-1].append(i+1)
        else:
            a = l[0].pop()
            l[1].add(a)
            f[a].append(i+1)

    elif(s[i] == "1"):
        if(len(l[1]) == 0):
            err = 1
            break
        else:
            a = l[1].pop()
            l[0].add(a)
            f[a].append(i+1)
if(err):
    print(-1)
else:
    if(len(l[0]) == 0):
        print(len(f))
        for i in f:
            print(len(i), *i)

    else:
        print(-1)
