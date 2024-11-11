n=int(input(""))
i=0
lis_1=list()
lis_2=list()
while i<n:
    a,b=map(int,input("").split())
    lis_1.append(a)
    lis_2.append(b)
    i+=1
s=0
for i in lis_1:
    for j in lis_2:
        if i==j:
            s+=1
        else:
            s=s
print(s)