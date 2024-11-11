n = int(input())+1
i,sum = 1,0
while i<n:
  if i%3!=0 and i%5!=0: sum+=i
  i+=1
print(sum)