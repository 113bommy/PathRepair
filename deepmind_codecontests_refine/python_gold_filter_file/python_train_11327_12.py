N,M=map(int,input().split())
arr=[int(x) for x in input().split()]
s=[list(map(int,input().split())) for y in range(M)]
s.sort(key=lambda z: z[1], reverse=True)

sum_a=0
for a,b in s:
    arr+=[b]*a
    sum_a+=a
    if sum_a>=N:
        break

lst=sorted(arr)
ans=sum(lst[-N:])
print(ans)