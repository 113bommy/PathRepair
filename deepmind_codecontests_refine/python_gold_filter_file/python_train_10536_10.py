I =lambda:int(input())
M =lambda:map(int,input().split())
LI=lambda:list(map(int,input().split()))
for _ in range(I()):
    s=input()
    a,b,c,d=0,0,0,0
    for i in s:
        if i=="L":a+=1
        elif i=="R":b+=1
        elif i=="U":c+=1
        else:d+=1
    a=min(a,b)
    b=min(c,d)
    if b>0 and a>0:
        ans=(a*2)+(b*2)
        print(ans)
        print("U"*b+"R"*a+"D"*b+"L"*a)
    elif a==0 and b>0:
        print(2)
        print("UD") 
    elif b==0 and a>0:
        print(2)
        print("LR")
    else:
        print(0)


