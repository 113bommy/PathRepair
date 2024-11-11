t=int(input())
for _ in range(t):
    x,y=map(int,input().split())
    # x,y=y,x 
    a,b,c,d,e,f=map(int,input().split())
    c=[f,a,b,c,d,e] 
    # c[0],c[2],c[3],c[5]=c[2],c[1],c[5],c[3]
    # print(c)
    m=0
    for i in range(6):
        if c[i]<c[m]:
            m=i 
    j=(m+1)%6
    while(j!=m):
        c[j]=min(c[(j+1)%6]+c[(j-1+6)%6],c[j])
        j=(j+1)%6
    j=(m-1+6)%6 
    while(j!=m):
        c[j]=min(c[(j+1)%6]+c[(j-1+6)%6],c[j])
        j=(j-1+6)%6
    if x==0 and y>=0:
        print(y*c[2]) 
    elif x==0 and y<=0:
        print(abs(y)*c[5])
    elif y==0 and x>=0:
        print(abs(x)*c[0])
    elif y==0 and x<=0:
        print(abs(x)*c[3])
    elif x>0 and y>0:
        if y>x:
            print(x*c[1]+(y-x)*c[2]) 
        else:
            print(y*c[1]+(x-y)*c[0])
    elif x<0 and y<0:
        if(abs(y)>abs(x)):
            print(abs(x)*c[4]+(abs(y)-abs(x))*c[5])
        else:
            print(abs(y)*c[4]+(abs(x)-abs(y))*c[3])
    else:
        ans=0
        if(x>0):
            ans=ans+x*c[0] 
        if(y>0):
            ans=ans+y*c[2]
        if(x<0):
            ans=ans+abs(x)*c[3]
        if(y<0):
            ans=ans+abs(y)*c[5]
        print(ans)
            
        