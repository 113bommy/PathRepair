s1=input()
s2=input()
l=s1[:s1.index('|')]
r=s1[s1.index('|'):]
r=r.replace('|','')
if abs(len(r)-len(l))>len(s2) or (len(l)+len(r)+len(s2))%2:
    print('Impossible')
else:
    for i in s2:
        if len(r)>len(l):
            l+=i
        else:
            r+=i
    print(l+'|'+r)
