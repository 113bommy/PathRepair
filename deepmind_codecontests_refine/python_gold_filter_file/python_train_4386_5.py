n=int(input())
s=list(input())
for i in range(n-1):
    if s[i+1]<s[i]:
        del s[i]
        break
if len(s)==n:
    del s[-1]
print("".join(s))