n = int(input())
p = list(map(int,input().split()))
h1,h2 = [0]*n,[0]*n
for i in range(1,n):
    if p[i]>p[i-1]:
        h1[i] = h1[i-1]+1
for i in range(n-2,-1,-1):
    if p[i]>p[i+1]:
        h2[i] = h2[i+1]+1
m = max(max(h1),max(h2))
two,one = 0,h1.count(m)+h2.count(m)
for i in range(n):
    if h1[i]==m and h2[i]==m:
        two+=1
if two==1 and one==2 and m%2==0:
    print(1)
else:
    print(0)