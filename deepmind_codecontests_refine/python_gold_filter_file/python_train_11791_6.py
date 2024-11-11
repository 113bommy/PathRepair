s='codeforces'
ans=0
 
n=int(input())
z=[1]*10
y=[2]+[1]*9
 
Z,Y=1,1
ans=[]
for i in range(10*40):
    if Z>=n:
        ans=sum(z)
        break
    p=z[i%10]
    z[i%10]+=1
    Z//=p
    Z*=p+1
a=[]
for j in range(10):
    a+=[s[j]*z[j]]
print(''.join(a))