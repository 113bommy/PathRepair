n=int(input())
ans=[]
for i in range(1,int(n**0.5)+1):
    if n%i==0:
        de=i
        k=n//i
        last=de*(k-1)+1
        ans.append(int((1+last)*k//2))
        #print((1+n-(n+1)%i)*(n/i)/2,i)
        if n//i!=i:
            de=n//i
            k=n//de
            last=de*(k-1)+1
            ans.append(int((1+last)*k//2))
print(*sorted(set(ans)))