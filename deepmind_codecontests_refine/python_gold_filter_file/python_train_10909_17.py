n=int(input())
s=input()
ans=0
for i in range(1000,2000):
    templ=list(str(i))
    t=templ[1:]
    #print(t)
    p=0
    for q in range(n):
        if s[q]==t[p]:
            p+=1
        if p>2:
            ans+=1
            break         

print(ans)
