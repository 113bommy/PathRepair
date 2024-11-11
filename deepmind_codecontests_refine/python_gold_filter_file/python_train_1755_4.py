N = int(input())
Array = []
for i in range(N):
  Array.append(tuple(map(int,input().split())))

res = 0
for i in reversed(range(N)):
  a,b = Array[i]
  a+=res
  res+= ((b-a%b)%b)
print(res)