n=int(input())
a="zabcdefghijklmnopqrstuvwxy"
b=""
while n/26>0:
  b=a[n%26]+b
  n=(n-1)//26
print(b)