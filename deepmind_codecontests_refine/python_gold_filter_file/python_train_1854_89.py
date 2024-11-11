n=input()
ans='Good'
for i in range(1,len(n)):
  if n[i]==n[i-1]:
    ans='Bad'
print(ans)