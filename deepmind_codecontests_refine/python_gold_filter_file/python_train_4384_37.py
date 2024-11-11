w,h,k=[int(i) for i in input().split()]
s=0
for i in range(k):
    s=s+2*w+2*h-4
    w=w-4
    h=h-4
print(s)
