import math
for j in range(int(input())):
    b=int(input())
    a=list(map(int,input().strip().split()))[:b]
    # a.append(min(a))
    # print(a)
    # tempcount=count=0
    diff=sec=0
    maxx=float("-inf")
    ls=0
    for i in range(b):
        # print(i)
        # minimum=min
        if (a[i]<maxx):
            diff=max(diff,maxx-a[i])
            # print('diff  ',diff)
        maxx=max(maxx,a[i])    # tempcount=0
            # while not a[i]>=a[i-1]:
            #     # print('while')
            #     time+=1
            #     tempcount+=1
            #     a[i]+=pow(2,time-1)
            #     # print(a)
            # if tempcount>=count:
            #     count=tempcount
    while(ls<diff):
        sec+=1
        ls+=2**(sec-1)
    # while(diff!=0):
    #     print('ls  ',ls)
    #     # 
    #     sec=math.log2(diff)+1
    #     # ls=2**sec


    print(sec)
