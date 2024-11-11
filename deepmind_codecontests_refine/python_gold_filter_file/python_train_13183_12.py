a=list(input())
a.sort(reverse=True)
b=int(input())
ans=''
while(len(a)>0):
    for i in range(len(a)):
        x=ans+a[i]+''.join(sorted(a[:i]+a[i+1:]))
        if(int(x)<=b):
            ans+=a[i]
            a=a[:i]+a[i+1:]
            break
print(ans)
        
    