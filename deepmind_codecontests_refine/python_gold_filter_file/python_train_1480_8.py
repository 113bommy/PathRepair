a,b,c,d=map(int,input().split())

ans=[]
for i in range(a):
    ans.append(0)
    if(b):
        ans.append(1)
        b-=1

if(len(ans) and b and ans[-1]==0):
    ans.append(1)
    b-=1

tan=[]
for i in range(d):
    tan.append(3)
    if(c):
        tan.append(2)
        c-=1

flag=0    


if(len(tan) and c and tan[-1]==3):
    tan.append(2)
    c-=1

for i in range(1,len(ans)):
    if(ans[i]==ans[i-1]):
        print('NO')
        exit()
for i in range(1,len(tan)):
    if(tan[i]==tan[i-1]):
        print('NO')
        exit()
        
    
if(len(ans)==0 and len(tan)==0):
    if(abs(b-c)<=1):
        print('YES')
        if(b>c):
            i=0
            while(1):
                if(i%2==0):
                    if(b):
                        
                        print('1',end=" ")
                        i+=1
                        b-=1
                    else:
                        break;
                    
                else:
                    if(c):
                        print('2',end=" ")
                        i+=1
                        c-=1
                    else:
                        break;
            exit()
        else:
            i=0
            
            while(1):
                if(i%2==0):
                    if(c):
                        
                        print('2',end=" ")
                        i+=1
                        c-=1
                    else:
                        break;
                else:
                    if(b):
                        print('1',end=" ")
                        b-=1
                        i+=1
                    else:
                        break;
            exit()
                
    else:
        print('NO')
        exit()
if(len(tan)==0):
    i=0
    while(1):
        if(i%2==0):
            if(c and ans[-1]==1):
                c-=1
                ans.append(2)
                i+=1
            else:
                break;
        else:
            if(b and (ans[-1]==0 or ans[-1]==2)):
                ans.append(1)
                i+=1
                b-=1
            else:
                break;
    if(b==0 and c==0):
        print('YES')
        print(*ans)
        exit()
    if(b==1 and c==0):
        print('YES')
        print(1,end=" ")
        print(*ans)
        exit()
    print('NO')
    exit()
if(len(ans)==0):
    i=0
    while(1):
        
        if(i%2==0):
            if(b and tan[-1]==2):
                b-=1
                tan.append(1)
                i+=1
            else:
                break;
        else:
            if(c and (tan[-1]==1 or tan[-1]==3)):
                tan.append(2)
                i+=1
                c-=1
            else:
                break;
    if(b==0 and c==0):
        print('YES')
        print(*tan)
        exit()
    if(b==0 and c==1):
        print('YES')
        print(2,end=" ")
        print(*tan)
        exit()
    print('NO')
    exit()
    
                
    
for i in range(1,len(ans)):
    if(ans[i]==ans[i-1]):
        flag=1
        break;
for i in range(1,len(tan)):
    if(tan[i]==tan[i-1]):
        flag=1
        break;
if(flag==1):
    print('NO')
    exit()
    
p,q=b,c
one=ans.copy()
two=ans.copy()
i=0


if(ans[-1]==0 or tan[-1]==3):
    print('NO')
    exit()

while(1):
    if(i%2==0):
        if(c):
            c-=1
            one.append(2)
            i+=1
        else:
            break;
    else:
        if(b):
            b-=1
            one.append(1)
            i+=1
        else:
            break;


if(b==1):
    one=[1]+one
    b-=1
if(one[-1]==2):
    one.extend(tan)
    if(b==0 and c==0):
        print('YES')
        print(*one)
        exit()
if(one[-1]==1):
    if(tan[-1]==2):
        if(b==0 and c==0):
            print('YES')
            tan.reverse()
            one.extend(tan)
            print(*one)
            exit()

b,c=p,q
i=0
while(1):
    if(i%2==0):
        if(b):
            b-=1
            two.append(1)
            i+=1
        else:
            break;
    else:
        if(c):
            c-=1
            two.append(2)
            i+=1
        else:
            break;


if(c==1):
    two=[2]+one
    c-=1
if(two[-1]==1 and b==0 and c==0):
    two.extend(tan)
    print('YES')
    print(*one)
    exit()
if(two[-1]==2 and b==0 and c==0):
    if(tan[-1]==1):
        print('YES')
        tan.reverse()
        one.extend(tan)
        print(*one)
        exit()



print('NO')
exit()






