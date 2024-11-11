n = int(input())

oth = [4,7,44,47,74,77]
if n in oth:
    print(oth.index(n)+1)

else:
    lis = set()
    def find(current,le):
        if len(current) == le:
            lis.add(current)
            return
        
        for k in [4,7]:
            find(current+str(k),le)

    res = 1
    ans = 0
    for i in range(1,len(str(n))):
        res = res*2
        ans += res
    
    find('',len(str(n)))
    li = list(lis)
    li.sort()
    print(ans+li.index(str(n))+1)