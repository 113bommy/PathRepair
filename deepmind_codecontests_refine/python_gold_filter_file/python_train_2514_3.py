n=int(input())
s=input()
l1=list(map(int,input().split()))
l2=list(s)
for i in range(0,n):
    x=int(s[i])
    j=i
    if x<l1[x-1]:
        while x<=l1[x-1]:
            l2[j]=l1[x-1]
            j+=1
            if j==n:
                break
            x=int(s[j])
            
        break
print(''.join(str(x) for x in l2))
        