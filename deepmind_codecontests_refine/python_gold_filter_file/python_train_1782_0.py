il_rozgalezien=int(input())
d=[0, 0]+[int(x) for x in input().split()]
slownik={}
for i in range(2,il_rozgalezien+1):
    if d[i] in slownik:
        slownik[d[i]].append(i)
    else:
        slownik[d[i]]=[i]


il_lisci=[0]*(il_rozgalezien+1)

for i in range(il_rozgalezien,1,-1):
    if i not in slownik:
        il_lisci[i]=1
        il_lisci[d[i]]+=1
    else:
        il_lisci[d[i]]+=il_lisci[i]  

# print(il_lisci)
il_lisci.sort()
# print(il_lisci)
if il_rozgalezien==1:
    print(1)
else:
    print(*il_lisci[1::])
