n = int(input())
ans = n
for i in range(n+1):
    cont=0
    j = n-i
    while i>0:
        cont+=i%6
        i//=6
    while j>0:
        cont+=j%9
        j//=9
    ans=min(ans,cont)
print(ans)
