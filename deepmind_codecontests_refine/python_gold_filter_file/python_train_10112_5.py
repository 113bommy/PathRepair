from sys import stdin,stdout

I = stdin.readline
P = stdout.write

n,m = map(int,I().split())
arr = [int(x) for x in I().split()]
ans = []
occ = [0 for i in range(n)]
freq = [0 for i in range(n)]
l = 0
con = 1
for i in arr:
    freq[i-1]+=1
    if(occ[i-1] == 0):
        l+=1
        occ[i-1] = 1
    if(l == n):
        #con+=1
        l = 0
        occ = [0]*n
        for y in range(n):
            if(freq[y]>0):
                freq[y]-=1
                if(freq[y]>=1 and occ[y] == 0):
                    occ[y] = 1
                    l+=1
        ans.append("1")
    else:
        ans.append("0")
    
#print(freq,l)        
P("".join(ans))
    
    