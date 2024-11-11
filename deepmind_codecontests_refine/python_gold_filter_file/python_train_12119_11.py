n = int(input())
s = list(map(int,input().split()))
r1,r2 = 0,1
for i in range(n):
    if s[i]==i:
        r1+=1
    else:
        if i==s[s[i]]:
            r2+=1
print(min(n,r1+min(2,r2)))