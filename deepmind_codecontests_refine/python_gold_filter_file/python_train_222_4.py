n=int(input())
s=input()
a=s.count('0')
b=s.count('1')
if a!=b:
    print(1)
    print(s)
else:
    i=0
    if len(s)>=3:
        while i<len(s):
            if s[:i].count('0')!=s[:i].count('1') and s[i:].count('0')!=s[i:].count('1'):
                print(2)
                print(s[:i],s[i:])
                break
            i+=1
    else:
        print(2)
        print(*list(s))