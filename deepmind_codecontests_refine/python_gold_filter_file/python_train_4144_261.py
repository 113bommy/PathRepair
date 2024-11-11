a,b = map(int,input().split())
i = 0
while a*i+1-i<b:
  i += 1
print(i)