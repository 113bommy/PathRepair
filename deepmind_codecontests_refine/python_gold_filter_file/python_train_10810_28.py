s=input()
n=len(s)//2
 
for i in range(1,n):
  if s[:n-i]==s[n-i:2*n-2*i]:
    print(2*n-2*i)
    break