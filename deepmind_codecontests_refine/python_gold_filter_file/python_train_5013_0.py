q = int(input())
for _ in range(q):
    word = input()
    dic = {}
    for l in word:
        if l in dic:
            dic[l] += 1
        else:
            dic[l] = 1
    
    if len(dic) == 1:
        print(word)
    elif len(dic) == 2:
        k = list(dic.keys())
        k.sort()
        if ord(k[0]) + 1 == ord(k[1]):
            print("No answer")
        else:
            print(word)
    elif len(dic) == 3:
        k = list(dic.keys())
        k.sort()
        if ord(k[0]) + 1 == ord(k[1]) and ord(k[1]) + 1 == ord(k[2]):
            print("No answer")
        else:
            if ord(k[0]) + 1 == ord(k[1]):
                print(  k[0] * dic[k[0]]  +  k[2] * dic[k[2]]  +   k[1] * dic[k[1]]   )
            else:
                print(  k[2] * dic[k[2]]  +  k[0] * dic[k[0]]  +   k[1] * dic[k[1]]   )
    else:
        l = len(dic)
        w = l - (l%2)
        ans = ""
        k = list(dic.keys())
        k.sort()
        for i in range( l//2):
            
            ans += k[l//2 + i] * dic[k[l//2 + i]]
            ans += k[i] * dic[k[i]]
        if l & 1:
            ans += k[w] * dic[k[w]]
        print(ans)
