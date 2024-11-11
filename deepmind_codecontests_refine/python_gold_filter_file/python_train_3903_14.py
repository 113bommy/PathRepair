s=str(input())[::-1]
x=0
for i in range(len(s)):
    if s[i]=='4':
        x+=2**i
    else:
        x+=2**(i+1)
    # print(x)
print(x)