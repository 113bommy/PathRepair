import math
a=int(input())
for i in range(a):
    s,r=map(str,input().split())
    ans=[]
    from collections import defaultdict
    al=defaultdict(int)
    for i in range(len(s)):
        ans.append(ord(s[i])-65)
        al[ord(s[i])-65]=i
    mini=[math.inf for i in range(len(s))]
    mini[-1]=(ord(s[-1])-65)
    for i in range(len(s)-2,-1,-1):
        mini[i]=min(ord(s[i])-65,mini[i+1])
    flag=0
   
    
    for i in range(min(len(s),len(r))):
        if(s[i]>r[i]):
            flag=1
            temp=ans[i]
            ans[i]=mini[i]
            ans[al[mini[i]]]=temp
            t=''
            for i in range(len(ans)):
                t+=chr(ans[i]+65)
            
            if(t<r):
                print(t)
            else:
                print('---')
            break;
        if(s[i]<r[i]):
            print(s)
            flag=1
            break;
        if(s[i]==r[i]):
            if(mini[i]==ans[i]):
                continue;
            else:
                flag=1
                temp=ans[i]
                ans[i]=mini[i]
                ans[al[mini[i]]]=temp
                t=''
                for i in range(len(ans)):
                    t+=chr(ans[i]+65)
                
                if(t<r):
                    print(t)
                break;
   
    
    if(flag==0):
        if(s>=r):
            print('---')
        else:
            print(s)
        
                   
    
