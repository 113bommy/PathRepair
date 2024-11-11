k,r=input().split()
k=int(k)
r=int(r)
d=[]

for i in range(0,10000):
    if ((k*i)-r)%10==0:
        d.append(i)
        print(i)
        break
     
if d==[]:
    for j in range(1,10000):
        if (j*k)%10==0:
            print(j)
            break
            

