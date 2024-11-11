n=bin(int(input()))[2:]
for i in range(len(n)):
  if int(n[i])==1:
    print(len(n)-i, end=' ')