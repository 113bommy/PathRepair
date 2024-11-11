n = int(input())
for i in range(n//4+1):
  if (n-4*i)%7 == 0:
    print("Yes")
    quit()
print("No")