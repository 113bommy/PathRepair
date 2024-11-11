s=sorted(input())
t=sorted(input())[::-1]
if s<t:
    ans="Yes"
else:
    ans="No"
print(ans)