n=int(input())
li = list(map(int,input().split()))
a=0
for i in range(1,n):
  if li[i] == li[i-1]:
    li[i] = 0
    a+=1
print(a)   
