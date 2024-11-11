n = int(input())
r = range(1,101)
l = [0]*n

for x in r:
    for y in r:
        for z in r:
            t = x*x+y*y+z*z+y*z+z*x+x*y
            if t <= n:
                l[t-1] +=1
for i in l:
    print(i)