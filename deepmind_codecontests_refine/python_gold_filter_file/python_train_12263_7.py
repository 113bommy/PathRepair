N = int(input())
 
for i in range(0,N+1):
    if int(i*1.08)==N:
      print(i)
      exit()
print(":(")