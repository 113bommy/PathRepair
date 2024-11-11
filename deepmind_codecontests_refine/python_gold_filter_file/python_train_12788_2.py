a,b,c,d,e,f = map(int,input().split())

# 作れるか判定
def check(goal,ac,bd):
    flag = 0
    for x in range(int(goal//ac)+1):
            if (goal-ac*x)%bd == 0 : flag = 1 ; break
    return flag

# 水W、砂糖Sをまわす
anss = []
for w in range(100,f+1,100):
    for s in range(1,f-w+1):
        if check(w,100*a,100*b) and check(s,c,d) and s<=((w*e)/100):
            conc = 100*s/(w+s) # concentration
            anss.append([conc,w,s])

anss.sort(reverse=1)
if anss: w,s = anss[0][1],anss[0][2]
else: w,s = 100*a,0
print(w+s,s)
