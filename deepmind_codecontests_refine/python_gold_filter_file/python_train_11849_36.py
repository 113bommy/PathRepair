input()
S=input()
s=set(S)
a=1
for c in s:a=a*(S.count(c)+1)%(10**9+7)
print(a-1)
