l=int(input())
for i in range(21):
  if 2 ** i > l:
    n = i
    break

m = (n - 1) * 2
  
s = l -  2 ** (n - 1)
value = 2 ** (n - 1)

path_add = [0 for i in range(n - 1)]
path_add_value = [0 for i in range(n - 1)]

for i in range(n - 1):
  if s >= 2 ** (n - 2 - i) :
    s -= 2 ** (n - 2 - i)
    path_add[-(i + 1)] = 1
    path_add_value[-(i + 1)] = value
    value += 2 ** (n - 2 - i)
  
#print(path_add)
#print(path_add_value)
#print(s)  
  
print(n, m + sum(path_add))
for i in range(n - 1):
  print(i + 1, i + 2, 0)
  print(i + 1, i + 2, 2 ** i)
  
for i in range(n - 1):
  if path_add[i] == 1:
    print(i + 1, n, path_add_value[i]) 
  