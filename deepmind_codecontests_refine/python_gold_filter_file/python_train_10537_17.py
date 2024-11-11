T = int(input())
for _ in range(T):
    s = input()
    t = input()
    n = len(s)

    #store the indices for each alphabet
    pos = [[] for _ in range(26)]
    for i in range(n):
        pos[ord(s[i]) - 97].append(i)

    
    val = -1
    ans = 1
    for x in t:
        p = pos[ord(x) - 97]
        #alphabet is absent
        if not p:
            ans = -1
            break

        
        l, r = 0, len(p) - 1
        
        while(l <= r):
            mid = (l + r) // 2
            if p[mid] > val:
                r = mid - 1
            else:
                l = mid + 1

##        print(x, l, p)
        if l < len(p):
            val = p[l]
        else:
            ans += 1
            val = p[0]
    print(ans)
