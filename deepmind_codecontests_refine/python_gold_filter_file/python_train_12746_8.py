s=input()
n=len(s)
done=0
l=['A','H','I','M','0','T','U','V','W','X','Y']
temp=['B','C','D','E','F','G','J','K','L','N','P','Q','R','S','Z']
for i in range(n):
  if s[i]in l:
    if s[i]!=s[n-i-1]:
      done=1
      break
  
  if s[i] in temp:
    done=1
    break    
  
if done==1:
  print("NO")
else:
  print("YES")          
