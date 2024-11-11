s=input()
w=int(input())
a=[]
for i in range(len(s)):
  if i%w==0:a.append(s[i])
print(''.join(a))