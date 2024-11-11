n,m = map(int, input().strip().split(' '))
x = list(map(int, input().strip().split(' ')))
t = list(map(int, input().strip().split(' ')))
l1=[]
l2=[]
for i in range(n+m):
    if t[i]==0:
        l1.append(x[i])
    else:
        l2.append(x[i])
l1.sort()
l2.sort()
if len(l2)==1:
    print(n)
else:
    l3=[0]*m
    j=0
    i=0
    while(i<n):
        if l1[i]<l2[j]:
            l3[j]+=1
            i+=1
        elif j<m-1 and l1[i]>l2[j] and l1[i]<l2[j+1]:
            if (l1[i]-l2[j])<=(l2[j+1]-l1[i]):
                l3[j]+=1
                i+=1
            else:
                l3[j+1]+=1 
                i+=1
        elif j==m-1:
            l3[-1]+=1
            i+=1
        else:
            j+=1
            f=0
            while(j<m):
                if l1[i]>l2[j]:
                    j+=1
                else:
                    f=1
                    break
            j-=1
            
        
    for j in range(m):
        print(l3[j],end=" ")
    print()
                