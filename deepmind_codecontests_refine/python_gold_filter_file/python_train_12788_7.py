a,b,c,d,e,f = map(int,input().split())
a *= 100
b *= 100
den = -1
sugar = 0
water = 0
for i in range(0,f+1,a):
    for j in range(0,f-i+1,b):
        for k in range(0,f-i-j+1,c):
            for l in range(0,f-i-j-k+1,d):
                w = i+j
                s = k+l
                if w == 0: break
                if s/w > e/100: continue
                x = s/(w+s)
                if x > den:
                    den = x
                    water = w
                    sugar = s
        else:
            continue
        break
print(sugar+water,sugar)