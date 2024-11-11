s=input()
s=s.lower()
ans=""
for i in s:
    if i not in"aeiouy":
        ans+="."+i
print(ans)
    