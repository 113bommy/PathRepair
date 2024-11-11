m,n=map(int,input().split())
count=0
li=list(map(int,input().split()))
for i in range(len(li)-1):
  if(li[i+1]-li[i])>n:
    count=0
  else:
    count+=1
print(count+1)