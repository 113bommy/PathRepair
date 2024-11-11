import sys
zero,ones = map(int,input().split())
ans=''
if zero-ones >1:
    print(-1)
    sys.exit(0)
elif (zero-ones)==1:
    for i in range((ones+zero)):
        if i%2==0:
            ans+='0'
        else:
            ans+='1'
    print(ans)
    sys.exit(0)
elif ones==zero:
    res=''
    for i in range(ones):
        res+='10'
    print(res)
elif ones>zero:
    per=0
    if (ones%2)==0:
        per=(ones//2)-1
    else:
        per=ones//2
    if per>zero:
        print(-1)
        sys.exit(0)
    else:
        res=''
        c=0
        for i in range(ones-zero-1):
            c+=2
            res+='110'
        for i in range(zero-(ones-zero-1)):
            c+=1
            res += '10'
        for i in range(ones-c):
            res+='1'
        if (ones-zero-1)==(ones/2):
            print(res[0:len(res)-1])
        else:
            print(res)













