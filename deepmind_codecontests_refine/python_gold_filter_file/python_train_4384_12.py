w,h,k=map(int,input().split())
p=0
for i in range(k):
    p+=(w+h)*2-4
    w-=4
    h-=4
print(p)
