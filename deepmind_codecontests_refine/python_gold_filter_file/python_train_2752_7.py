T=int(input())
l=list(map(int,input().split()))
even=0
odd=0
cri=0
for i in range(len(l)):
    if(l[i]<0 and even==0):
        cri+=1
    elif(l[i]<0 and even!=0):
        even-=1
    elif(l[i]>0):
        even+=l[i]
    else:
        pass
print(cri)
        
    