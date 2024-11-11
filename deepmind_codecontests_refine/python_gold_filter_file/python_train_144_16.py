a,b=(map(int,input().split()))
l=list((map(int,input().split())))
m=int(0)
for i in range (a-1):
    if m<l[i]-l[i+1]-b:
        m=l[i]-l[i+1]-b
print(m)
