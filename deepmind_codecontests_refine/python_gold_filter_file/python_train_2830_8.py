n=int(input())

a=input()

b=input()

f=1
ia=[]
ib=[]
cnt=[0]*26
for i in range(n):
    cnt[ord(a[i])-97]+=1
    cnt[ord(b[i])-97]+=1 
for i in range(26):
    if cnt[i]%2==1:
        f=0
        break 
if f==0:
    print(-1)
else:
    
        

    for i in range(1,n+1):
        if a[i-1]!=b[i-1] and a[i-1]=='a':
            ia.append(i)
        elif a[i-1]!=b[i-1] and a[i-1]=='b':
            ib.append(i)
    ans=len(ia)//2+len(ib)//2
    a1=0
    a2=0
    if len(ia)%2==1 :
        a1=ia[-1]
        a2=ib[-1]
        ans+=2 
        print(ans)
        print(a2,a2)
        print(a1,a2)
    else:
        print(ans)
    
        
        
    i=0
    l=0
    while(i<len(ia)//2):
        
        print(ia[l],ia[l+1])
        l+=2
        i+=1
    i=0
    l=0
    while(i<len(ib)//2):
        
        print(ib[l],ib[l+1])
        i+=1
        l+=2
        
        
        
    
    
            
        
        