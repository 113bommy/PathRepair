a=int(input())
s=input()
ans=[0]
flag=0
g1=[[s[0],0,0]]

def fit(g1,si,i):
    r=len(g1)-1
    while(r>=0 and g1[r][0]>s[i] and g1[r][1]==0):
        r-=1
    if(r<0):
        g1.insert(0,[si,1,i])
        return 1;
    
        
    if(g1[r][0]>si and g1[r][1]==1):
        return 0;

    g1.insert(r+1,[si,1,i])
    return 1;
    
for i in range(1,len(s)):


    if(s[i]>=g1[-1][0]):
       
        g1.append([s[i],0,i])
        continue;
    if(fit(g1,s[i],i)):
        continue;
    else:
        flag=1
        break;
if(flag==1):
    print('NO')
    exit(0)
print('YES')

g1.sort(key=lambda x:x[2])
for i in range(len(g1)):
    print(g1[i][1],end="")
    

    
        
        
