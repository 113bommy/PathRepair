a = int(input())
s=[int(c) for c in input().split()]
res=0
for i in range(1,a-1):
    if (s[i]>s[i-1] and s[i]>s[i+1]) or (s[i]<s[i-1] and s[i]<s[i+1]):
        res+=1
print(res)
