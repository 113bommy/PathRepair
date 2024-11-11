import collections

def main():
        n = int(input())
        arr = map(int,input().split())
        r1,r2 = [],[]
        # hash_t = collections.OrderedDict()
        hash_t = {}
        for i in arr:
            if hash_t.get(i) == None:
                hash_t[i] = 0
            hash_t[i] +=1
        for i,t in hash_t.items():
            if(t) >2:
                return 0,0
            if t == 1:
                r2.append(i)
            if t == 2:
                r1.append(i)
                r2.append(i)
        return r1,r2
r1 , r2 = main()
if r1==0 and r2 == 0:
    print("NO")
else:
    print("YES")
    print(len(r1))
    print(*sorted(r1))
    print(len(r2))
    print(*sorted(r2,reverse = True))