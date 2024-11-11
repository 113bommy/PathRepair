
n=int(input())
s=input()
a=[int(x) for x in str(s)]
a.sort()
l=[]
#print(a)
c=0
for i in range(n):
    if(a[i]==1 or a[i]==0):
        c+=1
a=a[c:]
#print(a)
for i in range(len(a)):
    if(a[i] != 2 and a[i]&(a[i]-1)==0):
        res=a[i]
        c=0
        while(res%2==0):
            res//=2
            c+=1
        a[i]-=1
        l+=[2]*c
        #print(a[i],end=" ")
    elif(a[i]%6==0):
        c=0
        res=a[i]//6
        if(res&(res-1)==0):
            while(res%2==0):
                res//=2
                c+=1
            a[i]-=1
            l+=[3]+[2]*c
    elif(a[i]==9):
        a[i]-=2
        l+=[3]*2+[2]
a+=l

a.sort(reverse=True)
for i in range(len(a)):
    print(a[i],end="")
print()