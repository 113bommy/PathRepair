s,y=(input() for i in range(2))
ans="{"*len(s);pa=ans
for i in range(len(s)-len(y)+1):
  for j in range(len(y)):
    if s[i+j]!='?' and s[i+j]!=y[j]:break
  else:ans=min(ans,s[:i].replace("?","a")+y+s[i+len(y):].replace("?","a"))
if pa==ans:print("UNRESTORABLE")
  
else:print(ans)
