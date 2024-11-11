s = input()
ans=0
 

for i in range(1,4):
  R = 'R'*i
  if R in s:
    ans = i
    
print(ans)