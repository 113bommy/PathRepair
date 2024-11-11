x=int(input())
t=0
p=[]
q=[]
for n in range(x):
 if x==1:
     a,b=map(int,input().split())
     t=a*b
 elif n!=x-1:   
    a,b=map(int,input().split())
    q.append(a)
    if len(p)==0:
        p.append(b)
    else:
        if b>=p[len(p)-1]:
            p=p
        else:
            q=q[0:len(q)-1]
            aa=sum(q)
            t=t+aa*p[0]
            q=[]
            q.append(a)
            p=[]
            p.append(b)
 else:
    
     a,b=map(int,input().split())
     if b>=p[len(p)-1]: 
         q.append(a)
         p.append(b)
         p.sort()
         aa=sum(q)
         t=t+aa*p[0]
     else:
         aa=sum(q)
         t=t+p[0]*aa
         q=[]
         p=[]
         q.append(a)
         p.append(b)
         t=t+q[len(q)-1]*p[len(p)-1]
       
print(t)     
     
    
