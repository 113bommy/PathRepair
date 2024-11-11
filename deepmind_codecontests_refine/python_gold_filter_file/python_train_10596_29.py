i= list(map(int, input().split()))
j=1
while i[0]>=i[1]**j:
  j+=1
print(j)