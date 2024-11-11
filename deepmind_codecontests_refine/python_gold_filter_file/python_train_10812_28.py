# coding : utf-8
s=list(map(lambda c:ord(c)-ord('a'),input()))
k=int(input())
for i in range(len(s)):
    if 26-s[i]<=k and s[i]!=0:
        k-=(26-s[i])
        s[i]=0
s[-1]=(s[-1]+k)%26
for n in s:
    print(chr(ord('a')+n),end='')
print()
