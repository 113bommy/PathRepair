N = int(input())
S = input()
numbers=[str(i).zfill(3) for i in range(1000)]
 
count=0
for num in numbers:
  j=0
  for i in range(N):
    if num[j]==S[i]:
      j+=1
      if j==3:
        count+=1
        break
print(count)