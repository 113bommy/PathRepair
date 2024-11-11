def beautifulstring(s):
    abc = {'a','b','c'}
    s+='?'
    s =list(s)
    for i in range(len(s)-1):
        if s[i]=='?':
            c = abc.difference(s[i-1],s[i+1])
            c = c.pop()
            s[i]=c
    s.pop(len(s)-1)        
    return ''.join(s)    
for _ in range(int(input())):
    string = input()
    string = beautifulstring(string)
    ans = string
    for i in range(len(string)-1):
        if string[i]==string[i+1]:
            ans = -1
    print(ans)        
    
