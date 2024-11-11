n,b,a=map(int,input().split())
z=a
li=list(map(int,input().split()))
ans=0
for i in range(0,len(li)):
    if li[i]==0:
        if a>0:
            a=a-1
            ans+=1
        else:
            if b>0:
                b=b-1
                ans+=1
            else:
                break
                
    else:
        if a==z:
            a=a-1
            ans+=1
        else:
            if b>0:
                b=b-1
                a+=1
                ans+=1
            else:
                if b==0 and a>0:
                    ans+=1
                    a-=1
                else:
                    break
print(ans)
        
    
