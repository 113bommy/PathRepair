s=input()
n=int(s[:-1])
s=s[-1]
print((n-1)//4*16+(1-n%2)*7+'1fedabc'.find(s))