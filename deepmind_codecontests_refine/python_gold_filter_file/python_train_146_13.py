n=int(input())
q=map(int,input().split())
f=list(q)
#print(f)
i=0
w=0
l=len(f)
x=f.count(200)
y=f.count(100)
#print(x,y)
while i<l:
    t=f[i]
    w=w+t
    i+=1
v=w
k=v%100
if n>1:
    if k==0:
        if y%2==0 and x==0:
            print("YES")
        elif x%2==0 and y==0:
            print("YES")
        elif x%2==0 and y%2==0:
            print("YES")
        elif y==2*x:
            print("YES")
        elif x%2!=0 and y%2==0 and y>0:
            print("YES")
        else:
            print("NO")
    elif k!=0 or x%2!=0 :
            print("NO")
  
    else:
        print("NO")
   
        
if n<=1:
    print("NO")
    

