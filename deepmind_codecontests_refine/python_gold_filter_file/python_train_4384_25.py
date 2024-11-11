w,h,k=map(int,input().split())
a=0
for i in range(k):
  a+=(w+h)*2-4
  w-=4;
  h-=4;
print(a)