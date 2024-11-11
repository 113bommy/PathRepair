t=int(input())
S=0
for i in list(range(t+1)):
  if i%5!=0 and i%3!=0:
    S += i
print(S)
