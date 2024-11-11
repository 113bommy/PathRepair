N=int(input())
ct=0
while N>1:
  N=N//2
  ct+=1
print(2**ct)