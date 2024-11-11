MOD=(10**9+7)
x,y=map(int,input().split())
lis=[x,y,y-x,-x,-y,x-y]
for i in range(6):
                if lis[i]>=MOD:lis[i]=lis[i]%MOD
                elif lis[i]<0:lis[i]=lis[i]+MOD
n=int(input())
cr=lis[n%6 -1]
if cr>=MOD:
	cr=cr%MOD
elif cr<0:
	cr=cr+MOD
#print(lis)
print(cr)