t = int(input())
for _ in range(t):
    s = list(input())
    cnt = [0]*3
    kl = [[] for _ in range(3)]
    for i,c in enumerate(s):
        if c.islower():
            cnt[0]+=1
            kl[0].append(i)
        elif c.isupper():
            cnt[1]+=1
            kl[1].append(i)
        elif c.isdigit():
            cnt[2]+=1
            kl[2].append(i)
    if cnt.count(0)==0:
        s = "".join(s)
        print(s)
    elif cnt.count(0)==2:
        s= "".join(s)
        if cnt[0]>0:
            print(s[:-2]+"A1")
        elif cnt[1]>0:
            print(s[:-2]+'a1')
        elif cnt[2]>0:
            print(s[:-2]+'aA')
    else:
        if cnt[0]==0:
            if cnt[1]>1:
                s[kl[1].pop()] = 'a'
            else:
                s[kl[2].pop()] = 'a'
        elif cnt[1]==0:
            if cnt[0] > 1:
                s[kl[0].pop()] = 'A'
            else:
                s[kl[2].pop()] = 'A'
        elif cnt[2]==0:
            if cnt[1] > 1:
                s[kl[1].pop()] = '1'
            else:
                s[kl[0].pop()] = '1'

        s = "".join(s)
        print(s) 