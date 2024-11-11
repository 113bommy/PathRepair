a,b,c,d=map(int,input().split())

if   (a>b and (d!=0 or c!=0)):
    print("NO")
elif a==1 and b==0 and c==0 and d==0:
    print("YES")
    print(0)
elif a==0 and b==1 and c==0 and d==0:
    print("YES")
    print(1)
elif a==0 and b==0 and c==1 and d==0:
    print("YES")
    print(2)
elif a==0 and b==0 and c==0 and d==1:
    print("YES")
    print(3)    
elif a==0 and b==0:
    ans=[]
    if d==c:
        for i in range(c):
            ans.append(2)
            ans.append(3)
        print("YES")    
        print(*ans)    
    elif c-d==1:
        for i in range(d):
            ans.append(2)
            ans.append(3)
        ans.append(2)
        print("YES")
        print(*ans)
    elif d-c==1:
        for i in range(c):
            ans.append(3)
            ans.append(2)
        ans.append(3)
        print("YES")
        print(*ans)
    else:
        print("NO")
elif a==b:
    ans=[]
    
    if d==c or d==c-1:
        for i in range(a):
            ans.append(0)
            ans.append(1)
        for i in range(d):
            ans.append(2)
            ans.append(3)
        if d==c-1:
            ans.append(2)
        print("YES")
        print(*ans)    
    else:
        print("NO")
else:
    ans=[]
    if(b-a>c-d):
        for i in range(a):
            ans.append(1)
            ans.append(0)
        ans.append(1)
        if c>=(b-a-1):
            for i in range(b-a-1):
                ans.append(2)
                ans.append(1)
            if d==c-(b-a-1) or d==c-(b-a-1)-1:
                for i in range(d):
                    ans.append(2)
                    ans.append(3)
                if  d==c-(b-a-1)-1:
                    ans.append(2)
                print("YES")
                print(*ans)
            else:
                print("NO")
        else:
            print("NO")
    else:
        for i in range(min(a,b)):
            ans.append(0)
            ans.append(1)
        if c>=(b-a) and c!=0:
            for i in range(b-a):
                ans.append(2)
                ans.append(1)
            if d==c-(b-a) or d==c-(b-a)-1:
                for i in range(d):
                    ans.append(2)
                    ans.append(3)
                if  d==c-(b-a)-1:
                    ans.append(2)
                print("YES")
                print(*ans)
            else:
                print("NO")
        elif a-b==1:
            ans.append(0)
            print("YES")
            print(*ans)
        else:
            print("NO")
        