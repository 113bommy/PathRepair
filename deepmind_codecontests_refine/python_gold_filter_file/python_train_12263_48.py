n=int(input())

for i in range (n+1):
  k=i*1.08
  if int(k)==n:
    print (i)
    exit()
print (':(')