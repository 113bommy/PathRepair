k=int(input())
list=[1,2,3,4,5,6,7,8,9]
for i in range(k-1):
  m=list[i]
  n=m*10+m%10
  if m%10!=0:
    list.append(n-1)
  list.append(n)
  if m%10!=9:
    list.append(n+1)
print(list[k-1])