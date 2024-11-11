q=input()
b=0
y=0
i=0
w=q.split()
n=int(w[0])
t=int(w[1])
q=input()
a=q.split()
while y==0:
  a[i]=86400-int(a[i])
  b=b+a[i]
  if t<=b  :
    print(i+1)
    y=1
  i=i+1