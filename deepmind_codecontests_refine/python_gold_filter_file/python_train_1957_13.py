n=int(input())
s=input()
ans=''
for i in range(len(s)):
    ans+=chr((ord(s[i])-65+n)%26+65)
print(ans)