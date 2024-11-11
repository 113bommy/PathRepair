s=input()
a=int(input())
r=[]
for i in range(len(s)):
  for j in range(i+1,min(a+i,len(s))+1):
    r.append(s[i:j])
r=list(set(r))
r.sort()
print(r[a-1])