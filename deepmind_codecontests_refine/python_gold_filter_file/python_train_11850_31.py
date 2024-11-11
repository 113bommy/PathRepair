N,M =[int(i)for i in input().split()]
l=[]
for i in range(1,int(M**0.5+2)):
    if M%i==0:
        if M/i >= N:
            l.append(i)
        if i >= N:
            l.append(M/i)
print(int(max(l)))