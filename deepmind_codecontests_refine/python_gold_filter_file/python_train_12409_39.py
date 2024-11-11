l,r = map(int,input().split())
f = 0
for i in range (l,r + 1):
    s = str(i)
    if len(set(s)) == len(s):
        f = 1
        print (i)
        break
if f == 0:
    print (-1)