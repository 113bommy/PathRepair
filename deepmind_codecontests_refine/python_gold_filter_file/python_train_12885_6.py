A=input()
B=input()

ans=0
for a,b in zip(A,B):
    if a!=b:
        ans+=1
print(ans)
