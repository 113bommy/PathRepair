n=int(input())
L=[]
for i in range(1,n+1):
    sum1=0
    x=list(map(int,input().split()))
    sum1=sum(x)
    L.append(sum1)
    if i==1:
        z=sum1
L.sort(reverse=True)

for j in range(len(L)):
    if L[j]==z:
        print (j+1)
        break
