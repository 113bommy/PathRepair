s=input()
lst=['a','e','i','o','u','1','3','5','7','9']
cnt=0
for i in s:
    if i in lst:
        cnt+=1
print(cnt)