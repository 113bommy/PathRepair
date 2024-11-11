a=input()
ans=0
for i in range(len(a)+1):
    ans+=26
print(ans-len(a))    