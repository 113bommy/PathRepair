q=[int(x) for x in input().split()]
a=[int(x) for x in input().split()]
n=q[0]
m=q[1]
k=q[2]
mx1=max(a)
a.remove(mx1)
mx2=max(a)
a1=mx1*k+mx2
z=m//(k+1)
ans=a1*z
z2=m%(k+1)
ans=ans+(mx1*z2)
print(int(ans))

