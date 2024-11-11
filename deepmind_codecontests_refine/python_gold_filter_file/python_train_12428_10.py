n=int(input())
l=list(map(int,input().split()))
l1=[]
for i in range(1,n+1):
    l1.append(i)
l.sort()
#print(l)
#print(l1)
su=0
for i in range(n):
    su+=abs(l1[i]-l[i])
print(su)
