a=input()
ans="CODEFESTIVAL2016"
diff=0
for i in range(16):
  if a[i]!=ans[i]:
    diff+=1
print(diff)