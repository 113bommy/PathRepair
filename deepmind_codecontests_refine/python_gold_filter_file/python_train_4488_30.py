n , m = map(int,input().split())
s = list(input())
fre=[0]*26
for i in range(n):
    fre[ord(s[i])-ord('A')]+=1
ans = min(fre[:m])*m
print(ans)    