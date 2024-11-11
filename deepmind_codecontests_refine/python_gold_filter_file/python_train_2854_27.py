n = int(input())
s = list(map(int,input().split()))
a,b=0,0
for i in range(n-2):
    #print(i,s[i],s[i+1],s[i+2])
    if s[i+2]==s[i]+s[i+1]:
        a+=1
        b = max(b,a)
    else:
        a=0
print(min(n,b+2))
