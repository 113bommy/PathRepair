import math
def prime(n):
    if n==2 or n==3 :
        return 1
    if n%2==0 or n%3==0 or n==1:
        return 0
    p=math.sqrt(n)
    w=2
    for i in range(5,int(p)+1,w):
        if n%i==0:
            return 0
        w=6-w
    return 1
n=int(input())
a=list(map(int,input().rstrip().split()))
y=set()
for i in range(2,2*n+1):
    if prime(i):
        y.add(i)
#print(y)
count1=a.count(1)
count2=a.count(2)
if count1==0 or count2==0:
    print(*a)
    exit()
ini=0
ans=[]
for i in range(n):
    if ini+1 in y and count1>0:
        ans.append(1)
        count1-=1
        ini=ini+1
    elif ini+2 in y and count2>0:
        ans.append(2)
        count2-=1
        ini+=2
    else:
        if count2>0:
            ans.append(2)
            count2-=1
            ini+=1
        else:
            ans.append(1)
            count1-=1
            ini+=2
print(*ans)
        
    
    
    
    
    
        
    
    
    
    

