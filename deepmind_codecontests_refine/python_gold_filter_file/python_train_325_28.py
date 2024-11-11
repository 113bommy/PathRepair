[n,x,y] = list(map(int, input().split(" ")))
a = list(map(int,input()[n-x:n]))
b = [0]*(x)
b[x-y-1]=1
count=0
for i in range(x):
      if a[i]!=b[i]:
            count+=1
print(count)