a=input()
b=['a','e','i','o','u','1','3','5','7','9']
ans=0
for i in a:
    if i in b:
        ans+=1
print(ans)