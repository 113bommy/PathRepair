a,b=input().split()

a=int(a)
b=int(b)

s=input()
n=len(s)
L=[]

x=0
y=0
hor=s.count('R')-s.count('L')
ver=s.count('U')-s.count('D')
L=[[0,0]]
for i in range(n):
    if(s[i]=='U'):
        y+=1
    elif(s[i]=='D'):
        y-=1
    elif(s[i]=='R'):
        x+=1
    else:
        x-=1
    L.append([x,y])
k=True
for i in range(n+1):
    x=L[i][0]
    y=L[i][1]
    if(hor==0 and ver==0 and x==a and b==y):
        print('Yes')
        k=False
        break
    elif(hor==0 and ver!=0 and x==a and (b-y)%ver==0 and (b-y)*ver>=0):
        print('Yes')
        k=False
        break
    elif(ver==0 and hor!=0 and y==b and (a-x)%hor==0 and (a-x)*hor>=0):
        print('Yes')
        k=False
        break
    elif(ver!=0 and hor!=0 and(b-y)%ver==0 and ver*(b-y)>=0 and (a-x)%hor==0 and hor*(a-x)>=0 and(b-y)//ver==(a-x)//hor):
        print('Yes')
        k=False
        break

if(k):
    print('No')

        
