n=int(input())
l=sorted(map(int,input().split()))
le=[]
lo=[]
for i in l:
    if i%2==0:
        le.append(i)
    else:
        lo.append(i)
    
 
sumd=len(le)-len(lo)       
if sumd>=2:
    print(sum(le[:sumd-1]))
elif(sumd<=-2):
    print(sum(lo[:-sumd-1]))
else:
    print(0)
    