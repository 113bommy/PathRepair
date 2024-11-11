#maachudayeduniya
n = int(input())
l = list(map(int,input().split()))
for i in l:
    i = i%998244353
sd = 0
for i in l:
    j = ""
    for u in range(len(str(i))):
        j = j+str(i)[u]*2
    sd = sd+(int(j)%998244353)*n
print(sd%998244353)    
    
    
    
    
















