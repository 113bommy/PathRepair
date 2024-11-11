n = int(input())
x = list(map(int, input() .split()))
p = x.count(1)
m = x.count(2)
PE = x.count(3)
t = min(p,m,PE)
a =[0]*n
b = [0]*n
c = [0]*n
j,k,l = 0,0,0
for i in range(n):
  if x[i] == 1:
    a[j] = i+1
    j+=1
  elif x[i] == 2:
    b[k] = i+1
    k+=1
  elif x[i] == 3:
    c[l] = i+1
    l+=1
print(t)
for i in range(n):
  if (a[i] == 0) or (b[i]==0) or (c[i] == 0):
      break
  else:
    print(a[i],b[i],c[i])