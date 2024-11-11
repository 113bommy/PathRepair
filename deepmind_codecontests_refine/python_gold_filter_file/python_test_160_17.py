t=int(input())
res=[]
for i in range(t):
    # n , m, rb, cb, rd, and cd 
    l=input().split()
    l=[int(j) for j in l]
    n=l[0]
    m=l[1]
    rb = l[2]
    cb = l[3]
    rd = l[4]
    cd = l[5]

    if (rb==rd or cb==cd): 
        res.append(0)
    elif (rb<rd and cb<cd):
        res.append(min(rd-rb,cd-cb))
    else:
        if (rb < rd) : 
            res.append(min(rd-rb,m-cd+m-cb))
        elif(cb < cd):
            res.append(min(n-rd+n-rb,cd-cb))
        else:
            # print("in req")
            res.append(min(n-rd+n-rb,m-cd+m-cb))


for i in res:
    print(i)