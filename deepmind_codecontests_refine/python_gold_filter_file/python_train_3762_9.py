n=int(input())
l1=list(map(int,input().split()))
l1.sort()
ss=0
for i in range (int(len(l1)/2)):
    sum1=l1[i]+l1[len(l1)-1-i]
    ss+=sum1**2
print(ss)
