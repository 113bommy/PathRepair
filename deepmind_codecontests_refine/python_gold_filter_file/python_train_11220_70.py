num = int(input())

list = list(map(int,input().split()))
list.sort()

a = 1

for i in list:
  a = a * i
  if a > 10**18:
    a = -1
    break
  
print(a)
