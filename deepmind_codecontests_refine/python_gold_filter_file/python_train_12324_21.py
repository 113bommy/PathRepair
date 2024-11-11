t=int(input())
x=0
for _ in range(t):
    s=input()
    if(s[0]=='+' and s[1]=='+') or (s[2]=='+' and s[1]=='+'):
        x+=1
    elif(s[0]=='-' and s[1]=='-') or (s[2]=='-' and s[1]=='-'):
        x-=1
print(x)