s=list(input())
K=int(input())
i=0
while i<len(s):
    if i==len(s)-1:
        s[i]=chr(97+(ord(s[i])-97+K)%26)
        break
    if K<abs(123-ord(s[i]))%26:
        i+=1
    elif K>=abs(123-ord(s[i]))%26:
        sub=abs(123-ord(s[i]))%26
        s[i]="a"
        K-=sub
        i+=1
print("".join(s))