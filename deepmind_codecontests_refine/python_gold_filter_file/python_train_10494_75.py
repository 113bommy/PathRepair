n,a,b,c,d = (int(i)-1 for i in input().split())
s = input()
if c<d:
    if ("##" in s[a+1:c]) or ("##" in s[b+1:d]): x = "No"
    else: x = "Yes"
else:
    if "..." in s[b-1:d+2]: x = "Yes"
    else: x = "No"
print(x)