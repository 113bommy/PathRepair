t=int(input())
while(t>0):
    c=0
    l=input()
    k=input()
    new1=list(k)
    new=list(l)
    q=[]
    for i in range(len(new1)):
        for j in range(len(new)):
            if new1[i]==new[j]:
                q.append(j+1)
    for a in range(len(q)-1):
        c+=abs(q[a]-q[a+1])
    t-=1
    print(c)

        

