n=int(input())
h=list(map(int,input().split(" ")))
m=h[0]
a=False
for i in h:
    if i+1<m:
        a=True
    if i>m:
        m=i
print('YNeos'[a::2])
