n = int(input())
lis = [int(e) for e in input().split()]
ct = []
c0 = 0
c1 = 0
for i in range(len(lis)):
    if lis[i]==0:c0+=1
    if lis[i]==1:c1+=1
ct.append(c0)
ct.append(c1)

for i in range(1,len(lis)):
    c0 = 0
    c1 = 0
    for j in range(i-1,-1,-1):
        if lis[j]==0:
            c0+=1
    for j in range(i,len(lis)):
        if lis[j]==1:
            c1+=1
    #print("c0=",c0)
    #print("c1=",c1)
    ct.append(c0+c1)

#print(ct)
print(max(ct))
    
