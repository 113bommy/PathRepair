
n,k=map(int,input().split())
minX,minY,maxX,maxY=k,n,0,0
countb=0
for j in range(n):
    a=input()
#    finding minX
    if ("B" in a):
        if j<minY:
            minY=j
        if(j>maxY):
            maxY=j
    # len=len(a)
    for i in range(len(a)):
        if a[i]=="B":
            countb+=1
            if ( i<minX):
                minX=i
            if (i>maxX):
                maxX=i
# print(minX,maxX,minY,maxY)
side=max((maxY-minY),(maxX-minX))
ans=(side+1)**2-countb
#print(side,countb)

if(side+1>k or side +1>n):
    print(-1)
elif(minX==k and minY==n and maxX==0 and maxY==0):
    print(1)
else:
    print(ans)
                
            
            