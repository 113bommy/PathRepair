N = int(input())
ga, sa, ba = map(int, input().split())
gb, sb, bb = map(int, input().split())
metal = [(ga, gb), (sa, sb), (ba, bb)]
metal.sort(reverse = True, key = lambda x:x[1]-x[0])
ga, gb = metal[0]
sa, sb = metal[1]
ba, bb = metal[2]
if ba<=bb:
    res = N
    for i in range(N//ga+1):
        for j in range((N-i*ga)//sa+1):
            k = (N-i*ga-j*sa)//ba
            tmp = k*bb+j*sb+i*gb+(N-i*ga-j*sa-k*ba)
            res = max(res, tmp)
elif sa<=sb:
    res = N
    for i in range(N//ga+1):
        j = (N-i*ga)//sa
        tmp = gb*i+sb*j+(N-i*ga-sa*j)
        res = max(res, tmp)
    k = res//bb
    res += (ba-bb)*k
elif ga<=gb:
    i = N//ga
    N+=i*(gb-ga)
    res = N
    for i in range(N//sb+1):
        j = (N-i*sb)//bb
        tmp = N+(sa-sb)*i+(ba-bb)*j
        res = max(res, tmp)
else:
    res = N
    ga, gb = gb, ga
    sa, sb = sb, sa
    ba, bb = bb, ba
    for i in range(N//ga+1):
        for j in range((N-i*ga)//sa+1):
            k = (N-i*ga-j*sa)//ba
            tmp = k*bb+j*sb+i*gb+(N-i*ga-j*sa-k*ba)
            res = max(res, tmp)
print(res)


            
