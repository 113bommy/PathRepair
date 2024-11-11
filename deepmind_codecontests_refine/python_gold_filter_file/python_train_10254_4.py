# import sys
# input=sys.stdin.readline

def fu(s):
    if len(s)%2==1:
        return s
    s1=fu(s[:len(s)//2])
    s2=fu(s[len(s)//2:])
    if s1<s2:
        return s1+s2
    else:
        return s2+s1

a=input()
b=input()
if fu(a)==fu(b):
    print("YES")
else:
    print("NO")