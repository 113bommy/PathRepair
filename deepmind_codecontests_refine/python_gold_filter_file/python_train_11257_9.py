import collections
n,k = list(map(int,input().split(' ')))
s = input()
c = 0
i = 1
l = []
if n==1:
    print('1')
else:
    while i<=n:
        d = int(k)
        j=int(i)
        
        while (j<n and s[j]==s[j-1] and d!=1):
            d-=1
            j+=1
            
        if d==1:
          l.append(s[i-1:j])  
        
        i = int(j+1)
    if len(l)==0:
        print('0')
    else:
        e = collections.Counter(l)
        b = list(e.values())
        print(max(b))
