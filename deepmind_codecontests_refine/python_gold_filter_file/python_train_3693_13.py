s = input()
l = (len(s)+1)//2
k = 'qwertyuiopasdfghjklzxcvbnm'
ans = 'NA'
for i in range(len(s)+1):
    for j in k:
        e = ''
        b = s
        b = s[:i]+j+s[i:]
        r = [x for x in b[-l:]]
        r.reverse()
        for c in r:
            e = e + c
        if b[:l] == e:
            ans = b
print(ans)



        
    
