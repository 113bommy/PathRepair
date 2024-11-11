a,b = [int(i) for i in input().split()]
start = list(input())
temp = start[:]
for i in range(0,b):
  for j in range(0,a-1):
    if start[j]=='B' and start[j+1]=='G':
      temp[j]='G' 
      temp[j+1]='B'
  start= temp[:]
print(''.join(temp))



