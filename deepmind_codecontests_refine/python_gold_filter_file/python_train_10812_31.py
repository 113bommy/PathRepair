s=input()
n=int(input())
l=""
for i in range(len(s)):
    f=(26+ord("a")-ord(s[i]))%26
    if n>=f:n-=f;l+="a"
    else:l+=s[i]
    if n==0:print(l+s[i+1:]);exit()
print(l[:-1]+chr(ord(l[-1])+n%26))