N=int(input())

li=[]
for i in range(1,int(N**0.5)+1):
  if N%i==0:
    li.append(i+N//i-2)
print(min(li))