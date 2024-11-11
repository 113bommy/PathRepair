t=int(input())
for i in range(t):
    s=input()
    l=len(s)
    if(l%2!=0):
        l1=s[0:int(l/2)]
        l2=s[int(l/2)+1:0]
    else:
        l1=s[0:int(l/2)]
        l2=s[int(l/2):]
    l11=list(l1)
    l22=list(l2)
    # print(l22)
    if(l!=1):
     if(l11==l22):
        print("YES")
     else:
        print("NO")
    else:
        print("NO")