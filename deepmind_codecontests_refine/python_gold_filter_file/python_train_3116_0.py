c=p=0;b=[0]*1000000
for _ in range(int(input())):
    x=int(input())
    if (c==x and p!=x) or b[0]==1 or c>x:print('No');continue
    print('Yes')
    if x>=1000000:continue
    p+=1;b[x]+=1
    while b[x]>1:p-=1;b[x]-=2;b[x-1]+=1;x-=1
    while b[c+1]==1 and c<999999:c+=1