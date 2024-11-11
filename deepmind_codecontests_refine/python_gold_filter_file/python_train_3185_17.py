(a,b)=map(int,input().split())
x=0
count=0
y=0

while a<=b:
  a=a*3
  b=b*2
  count+=1
print(count)