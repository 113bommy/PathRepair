s=input().strip()
k=int(input())
A=[]
for i in range(len(s)):
  for j in range(1,6):
    if i+j<=len(s):
      A.append(s[i:i+j])
B=sorted(list(set(A)))
print(B[k-1])
