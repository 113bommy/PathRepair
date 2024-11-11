n = int(input())
for i in range(1,n+1):
  if(int(i*1.08) == n):
    print(i)
    exit()
print(":(")