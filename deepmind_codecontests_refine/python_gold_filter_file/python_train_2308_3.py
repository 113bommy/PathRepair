a,b,c,d=map(int,input().split(" "))
ls=[a,b,c]
ls=sorted(ls)
ans=0
d1=abs(ls[1]-ls[0])
if(d1<d):
    ans=d-d1
if (abs(ls[2]-ls[1])<d):
    ans =ans+ d - abs(ls[2] - ls[1])
print(ans)