n = int(input())
a = [int(x) for x in input().split()]
c =[0]*2*100007
s =[0]*2*100007
result=0
dis=0
result_list=[]
for i in a:
    c[i]+=1
for i in range(len(c)):
    if c[i]>0:
        s[i]=c[i]
        result=c[i]
        dis=i
        break
for i in range(dis+1,len(c)):
    if c[i]>1:
        s[i]=max(s[i-1]+c[i],c[i-1]+c[i])
    else:
        s[i]=0
for i in range(1,len(s)):
    if c[i]+s[i-1]>result:
        result=c[i]+s[i-1]
        dis=i
    if c[i]+c[i-1]>result:
        result=c[i]+c[i-1]
        dis=i
for i in range(dis-1,-1,-1):
    if c[i]==1:
        pos=i
        break
    if c[i]==0:
        pos=i+1
        break
print(result)
for i in range(pos,dis+1):
    print(i,end=" ")
for i in range(dis,pos-1,-1):
    for j in range(1,c[i]):
        print(i,end=" ")
    