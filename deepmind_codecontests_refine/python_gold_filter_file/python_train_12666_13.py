import math
l,r,x,y = map(int,input().split())
if y%x!=0:
    print(0)
    quit()
aa=y//x
ans=0
l=l/x;r=r/x;
for i in range(1,int(math.sqrt(y/x))+1,1):
    if aa%i==0:
        a,b = i , (aa//i)
        if l<=a<=r and l<=b<=r:
            if math.gcd(a,b)==1:
                ans+=2
                if a==b:
                    ans-=1    
print(ans)
#                print(2*len(lis),lis)            
    
        

