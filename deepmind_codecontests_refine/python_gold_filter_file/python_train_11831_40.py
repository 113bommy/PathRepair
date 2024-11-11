s=input()
L=['a','u','i','o','e','1','3','5','7','9']

count=0
for i in range(len(s)):
  if s[i] in L:
    count=count+1
  
print(count)