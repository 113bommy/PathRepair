n,m=[int(i) for i in input().split()]
ans=min(n,m)
print(ans+1)
for i in range(ans+1):
    print(str(ans-i)+" "+str(i))
