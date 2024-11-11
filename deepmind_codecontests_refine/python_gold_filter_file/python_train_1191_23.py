n=int(input())
l=list(map(int,input().split()))
l1=sorted(l)
i=0
j=len(l)-1
si=0
ei=0
while(i<len(l)-1):
    if(l1[i]!=l[i]):
        si=i
        break
    i=i+1
while(j>=si and j>=0):
    if(l1[j]!=l[j]):
        ei=j
        break
    j=j-1
l2=l[si:ei+1]
l2.reverse()
l3=[]
k=0
for i in range(len(l)):
    if(i>=si and i<=ei):
        l3.append(l2[k])
        k+=1
    else:
        l3.append(l[i])
if(l3==l1):
    print("yes")
    print(si+1,ei+1,sep=" ")
else:
    print("no")
        
        
