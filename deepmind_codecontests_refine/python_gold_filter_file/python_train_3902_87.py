n,m = input().split()
n = int(n)
m = int(m)
flag=True

for i in range(1,n+1):
  if i%2 == 1:
    print('#'*m)
  else:
    if flag==True:
      print("."*(m-1)+"#")
    else:
      print("#"+"."*(m-1))
    flag = not flag