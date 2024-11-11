k=int(input())
n=input()
l,sum,ans=len(n),0,0
for i in range(0,l) :
    sum+=int(n[i])
a=sorted(n)
if sum>=k :
    print(0)
else :
    for i in range(0, l):
        sum += (9-int(a[i]))
        ans+=1
        if sum>=k :
            print(ans)
            exit()
